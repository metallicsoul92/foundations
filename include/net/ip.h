#ifndef FOUNDATIONS_NET_IP_H_
#define FOUNDATIONS_NET_IP_H_

// Standard header for fixed-size integer types
#ifndef STDINT_DEFINED
#include <stdint.h>
#define STDINT_DEFINED 1
#endif

// Define the IP structure as 'ip_t'
#ifndef IP_T_DEF
typedef struct ip ip_t;
#define IP_T_DEF 1
#endif

// Define IP type constants for IPv4 and IPv6
#ifndef IP_TYPES_DEFINED
#define IP_TYPE_IPV4 1
#define IP_TYPE_IPV6 2
#define IP_TYPES_DEFINED 1
#endif

// Allocate and initialize an IP structure based on the type and index.
// This function retrieves the IP address of the system's network interfaces.
ip_t *ip_getIP(uint8_t type, uint8_t atIndex);

// Free resources associated with an IP structure.
void ip_freeIP(ip_t * out);

// Convert an IP structure to an array of uint8_t (bytes).
uint8_t * ip_asuint8(ip_t * ip);

#endif // FOUNDATIONS_NET_IP_H_
