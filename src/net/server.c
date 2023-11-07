#include "../../include/net/server.h"
#include "../../include/collections/vector.h"
#include "../../include/net/ip.h"
#include "../../include/core/buffer.h"
#include "../../include/core/log.h"
#include <stdio.h>
#include <stdlib.h>


struct _serverConnection{
  ip_t * _clientIP; // IP address of Client
  buffer_t * _inputDataBuffer; //Buffer to be read from
  buffer_t * _outputDataBuffer; //Buffer to be written to
};

typedef struct _serverConnection serverConnection_t;

#ifndef SERVER_DEF
struct server{
  uint16_t _port;
  ip_t * _serverIP;
  uint32_t _maxConnections; //max amount of connections to the server
  uint32_t _currentConnections; //current amount of connections
  vector_t * _connections; // a vector of server connections
  logger_t *_serverLog; // pointer to the log file for the server.
  server_listen_func_t _listen;
};
#define SERVER_DEF 1
#endif

server_t * server_malloc(uint16_t port,uint8_t ipType, uint8_t ipAtIndex, uint32_t maxConnections) {
    server_t *out = (server_t *)malloc(sizeof(server_t));
    if (out != NULL) {
        // Initialize server fields
        out->_port = port;
        out->_maxConnections = maxConnections;
        out->_currentConnections = 0;


        // Initialize any other server fields, e.g., _connections, _serverLog, and _listen
        out->_connections = vector_malloc(sizeof(serverConnection_t), maxConnections);
        out->_serverLog = logger_malloc(LOG_IO_FILE_AND_STDERR,LOG_FORMAT_STRUCTURED,"server.log");
        out->_serverIP = ip_getIP(ipType, ipAtIndex);
        // out->_listen = ...;

        // Initialize your server-specific components as needed

        return out;
    }

    return NULL; // Memory allocation failed
}

void server_free(server_t *out) {
    if (out != NULL) {


        // Free any resources associated with the server, e.g., _connections, _serverLog
        free_vector(out->_connections);
        logger_close(out->_serverLog);
        ip_freeIP(out->_serverIP);
        // Free any other resources or components

        free(out);
    }
}


uint16_t server_getPort(server_t * out){
  return out->_port;
}

ip_t * server_getServerIP(server_t * out){
  return out->_serverIP;
}


uint32_t server_getMaxConnections(server_t * out){
  return out->_maxConnections;
}
uint32_t server_getCurrentConnections(server_t * out){
  return out->_currentConnections;
}

int server_addToServerConnections(server_t *out, ip_t *clientIP) {
    if (out == NULL || clientIP == NULL) {
        return -1; // Error: Invalid arguments
    }

    // Check if the server has reached the maximum connections limit
    if (out->_currentConnections >= out->_maxConnections) {
        return -2; // Error: Max connections limit reached
    }

    serverConnection_t *newConnection = (serverConnection_t *)malloc(sizeof(serverConnection_t));
       if (newConnection == NULL) {
           return -3; // Error: Memory allocation failed
       }
    newConnection->_clientIP = clientIP; // Assuming you want to store the client's IP
    // 1KB Buffer? TODO: Maybe look into making this a custom amount?
    newConnection->_inputDataBuffer =  buffer_malloc(sizeof(char)*1024);
    newConnection->_outputDataBuffer = buffer_malloc(sizeof(char)*1024);

    // Add the new connection to the vector
     vector_push(out->_connections, &newConnection);
     out->_currentConnections++;
     return 0;

}


void server_writeToLog(server_t *out, uint8_t level, const char *message, ...) {
    if (out == NULL || out->_serverLog == NULL) {
        return;  // Return early if the server or its log file is not properly initialized
    }

    va_list args;
    va_start(args, message);

    // Format the log message using vsnprintf
    char formattedMessage[256];  // Adjust the size as needed
    vsnprintf(formattedMessage, sizeof(formattedMessage), message, args);

    va_end(args);

    logMessage_t *logMessage = logMessage_malloc(level, formattedMessage);
    if (logMessage != NULL) {
        logger_log(out->_serverLog, logMessage);
        logMessage_free(logMessage);
    }
}

void server_set_listen_function(server_t *server, server_listen_func_t listen_func) {
    if (server != NULL) {
        server->_listen = listen_func;
    }
}
