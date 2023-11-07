#ifndef FOUNDATIONS_NET_CLIENT_H_
#define FOUNDATIONS_NET_CLIENT_H_ 1

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

// Define the client structure as 'client_t'
#ifndef CLIENT_T_DEF
typedef struct client client_t;
#define CLIENT_T_DEF 1
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

#ifndef CLIENT_LISTEN_FUNC_DEF
// Define a function pointer type for the listen function
typedef int (*client_listen_func_t)(client_t *client, int backlog);
#define CLIENT_LISTEN_FUNC_DEF 1
#endif

// Allocate and initialize a client structure.
client_t * client_malloc(uint16_t cid, int sd, uint16_t p, ip_t *sp, ip_t * cp, int st, buffer_t * idb, buffer_t * odb );

// Free resources associated with a client structure.
void client_free(client_t * out);

// Get the client's unique identifier.
uint16_t client_getClientID(client_t * out);

// Get the socket descriptor associated with the client.
int client_getsocketDescriptor(client_t * out);

// Get the port on which the client is listening.
uint16_t client_getport(client_t * out);

// Get the server's IP address to which the client is connected.
ip_t * client_getserverIP(client_t * out);

// Get the client's IP address.
ip_t * client_getclientIP(client_t * out);

// Get the current state of the client.
int client_getstate(client_t * out);

// Get the data buffer used to read from the client.
buffer_t * client_getInputdataBuffer(client_t * out);

// Get the data buffer used to write to the client.
buffer_t * client_getOutputdataBuffer(client_t * out);

// Set a custom listen function for the client to handle incoming connections.
void client_set_listen_function(client_t *client, client_listen_func_t listen_func);

// Read data from the input data buffer into a provided buffer.
size_t client_dataBufferRead(client_t * out , char * data, size_t length);

// Write data to the output data buffer from a provided buffer.
size_t client_dataBufferWrite(client_t * out, const char * data, size_t length);

#endif
