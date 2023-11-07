#ifndef FOUNDATIONS_NET_PEER_H_
#define FOUNDATIONS_NET_PEER_H_

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

#ifndef PEER_T_DEF
typedef struct peer peer_t;
#define PEER_T_DEF 1
#endif

#define PEER_E_INVALID_BROADCAST -1


#ifndef PEER_LISTEN_FUNC_DEF
// Define a function pointer type for the listen function
typedef int (*peer_listen_func_t)(peer_t *peer, int backlog);
#define PEER_LISTEN_FUNC_DEF 1
#endif

#ifndef PEER_BROADCAST_FUNC_DEF
// Define a function pointer type for the listen function
typedef void (*peer_broadcast_func_t)(peer_t *peer, const void *data, size_t dataLength);
#define PEER_BROADCAST_FUNC_DEF 1
#endif
// Allocate memory for the peer and initialize it
peer_t *peer_malloc(uint16_t port, uint8_t ipType, uint8_t ipAtIndex, size_t maxConnections);

// Free resources associated with the peer
void peer_free(peer_t *out);

// Get the port on which the peer is listening
uint16_t peer_getPort(peer_t *out);

// Get the current number of connected peers
size_t peer_getPeerCount(peer_t *out);

// Set thee listening function
void peer_set_listen_func(peer_t * out, peer_listen_func_t function);

// Set thee broadcasting function
void peer_set_broadcast_func(peer_t * out, peer_broadcast_func_t function);

// Send data from each of the output buffers to each of the peers on the peer list
int peer_Broadcast(peer_t *peer);

#endif
