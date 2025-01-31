#ifndef FOUNDATIONS_NET_CLIENT_H_
#define FOUNDATIONS_NET_CLIENT_H_

// Standard headers for size_t and fixed-size integers
#include <stddef.h>
#include <stdint.h>

// Forward declarations for external structures
typedef struct buffer buffer_t;  // Buffer structure (defined elsewhere)
typedef struct ip ip_t;          // IP address structure (defined elsewhere)

// Forward declaration of the client structure (defined in client.c)
typedef struct client client_t;

// Define a function pointer type for a custom listen function
typedef int (*client_listen_func_t)(client_t *client, int backlog);

// === Client Management Functions ===

// Allocate and initialize a new client structure
client_t *client_malloc(uint16_t client_id, int socket_descriptor, uint16_t port,
                        ip_t *server_ip, ip_t *client_ip, int state,
                        buffer_t *input_buffer, buffer_t *output_buffer);

// Free resources associated with a client structure
void client_free(client_t *client);

// Explicitly close the client's socket without freeing the object
void client_close(client_t *client);

// === Client Accessor Functions ===

// Get the client's unique identifier
uint16_t client_get_client_id(client_t *client);

// Get the socket descriptor associated with the client
int client_get_socket_descriptor(client_t *client);

// Get the port on which the client is listening
uint16_t client_get_port(client_t *client);

// Get the server's IP address to which the client is connected
ip_t *client_get_server_ip(client_t *client);

// Get the client's own IP address
ip_t *client_get_client_ip(client_t *client);

// Get the current state of the client
int client_get_state(client_t *client);

// Get the data buffer used for reading input
buffer_t *client_get_input_buffer(client_t *client);

// Get the data buffer used for writing output
buffer_t *client_get_output_buffer(client_t *client);

// === Client Utility Functions ===

// Set a custom listen function for handling incoming connections
void client_set_listen_function(client_t *client, client_listen_func_t listen_func);

// Read data from the client's input buffer into a provided buffer
size_t client_buffer_read(client_t *client, char *data, size_t length);

// Write data to the client's output buffer from a provided buffer
size_t client_buffer_write(client_t *client, const char *data, size_t length);

// Check if the client's socket connection is still open
int client_is_connected(client_t *client);

#endif  // FOUNDATIONS_NET_CLIENT_H_
