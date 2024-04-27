#include "../../include/net/client.h"

#include "../../include/net/ip.h"
#include "../../include/core/buffer.h"
#include "../../include/core/log.h"

#include <stdlib.h>

#ifndef CLIENT_DEF
struct client {
   uint16_t _clientID;  // Unique client identifier
   int _socketDescriptor;  // Socket descriptor for the client
   uint16_t _port;  // Port on which the client is listening
   ip_t * _serverIP;  // Server IP address
   ip_t * _clientIP;  // Client's IP address
   int _state;  // Client state
   buffer_t * _inputDataBuffer;  // Data buffer to read from
   buffer_t * _outputDataBuffer; // Data buffer to write to
   client_listen_func_t _listen;
   logger_t * _clientLog;
};
#define CLIENT_DEF 1
#endif


client_t * client_malloc(uint16_t cid, int sd, uint16_t p, ip_t *sp, ip_t * cp, int st, buffer_t * idb, buffer_t * odb ){
  client_t * out = malloc(sizeof(client_t));
  if(out != NULL){
  out->_clientID = cid;
  out->_socketDescriptor = sd;
  out->_port = p;
  out->_serverIP = sp;
  out->_clientIP = cp;
  out->_state = st;
  out->_inputDataBuffer = idb;
  out->_outputDataBuffer = odb;
  out->_clientLog = logger_malloc(LOG_IO_FILE, LOG_FORMAT_STRUCTURED, "client.log");
  out->_listen = NULL;
  logMessage_t * init = logMessage_malloc(LOG_LEVEL_INFO, "Initializing Client");
  logger_log(out->_clientLog, init);
  logMessage_free(init);
  }
  return out;
}
void client_free(client_t * out){
  buffer_free(out->_outputDataBuffer);
  buffer_free(out->_inputDataBuffer);
  ip_freeIP(out->_serverIP);
  ip_freeIP(out->_clientIP);
  logMessage_t * goodbye = logMessage_malloc(LOG_LEVEL_INFO, "Closing Client");
  logger_log(out->_clientLog, goodbye);
  logMessage_free(goodbye);

  logger_close(out->_clientLog);
  free(out);
}

uint16_t client_getClientID(client_t * out){
  return out->_clientID;
}
int client_getsocketDescriptor(client_t * out){
  return out->_socketDescriptor;
}
uint16_t client_getport(client_t * out){
  return out->_port;
}
ip_t * client_getserverIP(client_t * out){
  return out->_serverIP;
}
ip_t * client_getclientIP(client_t * out){
  return out->_clientIP;
}
int client_getstate(client_t * out){
  return out->_state;
}
buffer_t * client_getInputdataBuffer(client_t * out){
  return out->_inputDataBuffer;
}
buffer_t * client_getOutputdataBuffer(client_t * out){
  return out->_outputDataBuffer;
}

void client_set_listen_function(client_t *client, client_listen_func_t listen_func) {
    if (client != NULL) {
        client->_listen = listen_func;
    }
}

//Read from the input data buffer , write to the output data buffer
size_t client_dataBufferRead(client_t * out , char * data, size_t length){
  return buffer_read(out->_inputDataBuffer, data, length);
}
size_t client_dataBufferWrite(client_t * out, const char * data, size_t length){
  return buffer_write(out->_outputDataBuffer, data, length);
}
