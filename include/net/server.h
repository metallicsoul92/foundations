#ifndef FOUNDATIONS_NET_SERVER_H_
#define FOUNDATIONS_NET_SERVER_H_

// Standard header for size_t
#ifndef STDDEF_DEFINED
#include <stddef.h>
#define STDDEF_DEFINED 1
#endif

// Standard header for fixed-size integer types
#ifndef STDINT_DEFINED
#include <stdint.h>
#define STDINT_DEFINED 1
#endif

// Define the server structure as 'server_t'
#ifndef SERVER_T_DEF
typedef struct server server_t;
#define SERVER_T_DEF 1
#endif

// Define the buffer structure as 'buffer_t'
#ifndef BUFFER_T_DEF
typedef struct buffer buffer_t;
#define BUFFER_T_DEF 1
#endif

// Define the IP structure as 'ip_t'
#ifndef IP_T_DEF
typedef struct ip ip_t;
#define IP_T_DEF 1
#endif

#ifndef SERVER_LISTEN_FUNC_DEF
// Define a function pointer type for the listen function
typedef int (*server_listen_func_t)(server_t *client, int backlog);
#define SERVER_LISTEN_FUNC_DEF 1
#endif

// Allocate and initialize a server structure.
server_t * server_malloc(uint16_t port, uint8_t ipType, uint8_t ipAtIndex, uint32_t maxConnections);

// Free resources associated with a server structure.
void server_free(server_t * out);

// Get the port on which the server is listening.
uint16_t server_getPort(server_t * out);

// Get the server's IP address to which the server is bound.
ip_t * server_getServerIP(server_t * out);

// Get the maximum number of connections the server can handle.
uint32_t server_getMaxConnections(server_t * out);

// Get the current number of connections to the server.
uint32_t server_getCurrentConnections(server_t * out);

// Add a new server connection with the provided client IP to the server's connections.
int server_addToServerConnections(server_t *out, ip_t *clientIP);

// Write a log message with the specified level to the server's log.
void server_writeToLog(server_t *out, uint8_t level, const char *message, ...);

// Set a custom listen function for the server to handle incoming connections.
void server_set_listen_function(server_t *server, server_listen_func_t listen_func);

#endif
