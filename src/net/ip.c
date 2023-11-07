#include "../../include/net/ip.h"
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <ifaddrs.h> // Include the header for getifaddrs

struct ip4{
  uint8_t _address[4];
};

struct ip6{
  uint8_t _address[16];
};

struct ip{
  uint8_t _type;
  union {
    struct ip4 asipv4;
    struct ip6 asipv6;
  } _address;
};



ip_t *ip_getIP(uint8_t type, uint8_t atIndex) {
    ip_t *out = malloc(sizeof(ip_t));
    out->_type = type;
    int currentIndex = 0; // Initialize the current index
    struct ifaddrs *ifap, *ifa;

    switch (type) {
        case IP_TYPE_IPV4: {
            if (getifaddrs(&ifap) == 0) {
                for (ifa = ifap; ifa != NULL; ifa = ifa->ifa_next) {
                    if (ifa->ifa_addr && ifa->ifa_addr->sa_family == AF_INET) {
                        if (currentIndex == atIndex) {
                            struct sockaddr_in *sa = (struct sockaddr_in *)ifa->ifa_addr;
                            memcpy(out->_address.asipv4._address, &sa->sin_addr, 4);
                            freeifaddrs(ifap);
                            return out; // Found the address at the desired index
                        }
                        currentIndex++;
                    }
                }
                freeifaddrs(ifap);
            }
            break;
        }
        case IP_TYPE_IPV6: {
             if (getifaddrs(&ifap) == 0) {
                 for (ifa = ifap; ifa != NULL; ifa = ifa->ifa_next) {
                     if (ifa->ifa_addr && ifa->ifa_addr->sa_family == AF_INET6) {
                         if (currentIndex == atIndex) {
                             struct sockaddr_in6 *sa6 = (struct sockaddr_in6 *)ifa->ifa_addr;
                             memcpy(out->_address.asipv6._address, &sa6->sin6_addr, 16);
                             freeifaddrs(ifap);
                             return out; // Found the IPv6 address at the desired index
                         }
                         currentIndex++;
                     }
                 }
                 freeifaddrs(ifap);
             }
             break;
         }
     }

    free(out); // Free the memory if no address was found
    return NULL; // Address not found at the specified index
}

void ip_freeIP(ip_t * out){
    if (out) {
        free(out);
    }
}

uint8_t * ip_asuint8(ip_t * ip){
  uint8_t * out = NULL;

switch(ip->_type){
  case IP_TYPE_IPV4:
  out = malloc(sizeof(ip->_address.asipv4));
  if(out){
  memcpy(out, &ip->_address.asipv4, 4);
  }
  break;
  case IP_TYPE_IPV6:
  out = malloc(sizeof(ip->_address.asipv6));
  if(out){
  memcpy(out, &ip->_address.asipv6, 16);
  }
  break;
}

  return out;
}
