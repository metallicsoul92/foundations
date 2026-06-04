#include "../../include/net/client.h"
#include "../../include/net/ip.h"
#include "../../include/core/buffer.h"
#include "../../include/core/log.h"

#include <stdlib.h>
#include <unistd.h> // Required for close()
#include <sys/select.h> // Required for checking socket status
#include <pthread.h> // Required for mutex locks
#include <stdio.h>

#ifndef CLIENT_DEF
struct client {
   uint16_t _client_id;        // Unique client identifier
   int _socket_descriptor;     // Socket descriptor for the client
   uint16_t _port;             // Port on which the client is listening
   ip_t *_server_ip;           // Server IP address
   ip_t *_client_ip;           // Client's IP address
   int _state;                 // Client state
   buffer_t *_input_buffer;    // Data buffer to read from
   buffer_t *_output_buffer;   // Data buffer to write to
   client_listen_func_t _listen; // Custom listen function
   logger_t *_client_log;      // Logging object
   pthread_mutex_t _lock;      //  Mutex for thread safety
};
#define CLIENT_DEF 1
#endif

// === Client Management Functions ===
client_t *client_malloc(uint16_t client_id, int socket_descriptor, uint16_t port,
                        ip_t *server_ip, ip_t *client_ip, int state,
                        buffer_t *input_buffer, buffer_t *output_buffer) {
    client_t *client = malloc(sizeof(client_t));
    if (client == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory for client.\n");
        return NULL;
    }

    pthread_mutex_init(&client->_lock, NULL);  //  Initialize mutex

    client->_client_id = client_id;
    client->_socket_descriptor = socket_descriptor;
    client->_port = port;
    client->_server_ip = server_ip;
    client->_client_ip = client_ip;
    client->_state = state;
    client->_input_buffer = input_buffer;
    client->_output_buffer = output_buffer;
    client->_listen = NULL;

    // Safe logger initialization
    client->_client_log = logger_malloc(LOG_IO_FILE, LOG_FORMAT_STRUCTURED, "client.log");
    if (client->_client_log) {
        logMessage_t *init = logMessage_malloc(LOG_LEVEL_INFO, "Initializing Client");
        if (init) {
            logger_log(client->_client_log, init);
            logMessage_free(init);
        }
    } else {
        fprintf(stderr, "Warning: Failed to initialize client logger.\n");
    }

    return client;
}

void client_free(client_t *client) {
    if (client == NULL) return;

    pthread_mutex_lock(&client->_lock);  //  Lock before modifying state
    client_close(client);

    buffer_free(client->_output_buffer);
    buffer_free(client->_input_buffer);
    ip_freeIP(client->_server_ip);
    ip_freeIP(client->_client_ip);

    if (client->_client_log) {
        logMessage_t *goodbye = logMessage_malloc(LOG_LEVEL_INFO, "Closing Client");
        logger_log(client->_client_log, goodbye);
        logMessage_free(goodbye);
        logger_close(client->_client_log);
    }

    pthread_mutex_unlock(&client->_lock);  //  Unlock before destroying mutex
    pthread_mutex_destroy(&client->_lock); //  Destroy mutex before freeing memory

    free(client);
}

// === New Function: Close Client Socket ===
void client_close(client_t *client) {
    if (client == NULL) return;

    pthread_mutex_lock(&client->_lock);  //  Lock before modifying state

    if (client->_socket_descriptor >= 0) {
        close(client->_socket_descriptor);
        client->_socket_descriptor = -1; // Mark socket as closed
    }

    pthread_mutex_unlock(&client->_lock);  //  Unlock after modification
}

// === Client Accessor Functions ===
uint16_t client_get_client_id(client_t *client) {
    pthread_mutex_lock(&client->_lock);
    uint16_t id = (client != NULL) ? client->_client_id : 0;
    pthread_mutex_unlock(&client->_lock);
    return id;
}

int client_get_socket_descriptor(client_t *client) {
    pthread_mutex_lock(&client->_lock);
    int sd = (client != NULL) ? client->_socket_descriptor : -1;
    pthread_mutex_unlock(&client->_lock);
    return sd;
}

uint16_t client_get_port(client_t *client) {
    pthread_mutex_lock(&client->_lock);
    uint16_t port = (client != NULL) ? client->_port : 0;
    pthread_mutex_unlock(&client->_lock);
    return port;
}

ip_t *client_get_server_ip(client_t *client) {
    pthread_mutex_lock(&client->_lock);
    ip_t *server_ip = (client != NULL) ? client->_server_ip : NULL;
    pthread_mutex_unlock(&client->_lock);
    return server_ip;
}

ip_t *client_get_client_ip(client_t *client) {
    pthread_mutex_lock(&client->_lock);
    ip_t *client_ip = (client != NULL) ? client->_client_ip : NULL;
    pthread_mutex_unlock(&client->_lock);
    return client_ip;
}

int client_get_state(client_t *client) {
    pthread_mutex_lock(&client->_lock);
    int state = (client != NULL) ? client->_state : -1;
    pthread_mutex_unlock(&client->_lock);
    return state;
}

// === Client Utility Functions ===
void client_set_listen_function(client_t *client, client_listen_func_t listen_func) {
    pthread_mutex_lock(&client->_lock);
    if (client != NULL) {
        client->_listen = listen_func;
    }
    pthread_mutex_unlock(&client->_lock);
}

// Read data from the client's input buffer
size_t client_buffer_read(client_t *client, char *data, size_t length) {
    pthread_mutex_lock(&client->_lock);
    size_t bytes_read = (client == NULL || client->_input_buffer == NULL || data == NULL) ? 0
                        : buffer_read(client->_input_buffer, data, length);
    pthread_mutex_unlock(&client->_lock);
    return bytes_read;
}

// Write data to the client's output buffer
size_t client_buffer_write(client_t *client, const char *data, size_t length) {
    pthread_mutex_lock(&client->_lock);
    size_t bytes_written = (client == NULL || client->_output_buffer == NULL || data == NULL) ? 0
                           : buffer_write(client->_output_buffer, data, length);
    pthread_mutex_unlock(&client->_lock);
    return bytes_written;
}

// === New Function: Check if Client is Still Connected ===
int client_is_connected(client_t *client) {
    pthread_mutex_lock(&client->_lock);
    if (client == NULL || client->_socket_descriptor < 0) {
        pthread_mutex_unlock(&client->_lock);
        return 0;
    }

    fd_set read_set;
    struct timeval timeout = {0, 0};  // Zero timeout for non-blocking check

    FD_ZERO(&read_set);
    FD_SET(client->_socket_descriptor, &read_set);

    int result = (select(client->_socket_descriptor + 1, &read_set, NULL, NULL, &timeout) > 0) ? 1 : 0;

    pthread_mutex_unlock(&client->_lock);
    return result;
}
