#include "../../include/net/peer.h"
#include "../../include/net/ip.h"
#include "../../include/collections/vector.h"
#include <stdlib.h>

struct _peerConnection{
  ip_t * _pairIP;
  buffer_t * _inputDataBuffer;
  buffer_t * _outputDataBuffer;
};

typedef struct _peerConnection peerConnection_t;

struct peer{
  uint16_t _port;
  ip_t * _peerIP;
  vector_t * _peerList; //a vetor of peerConnections.
  peer_listen_func_t _listen;
  peer_broadcast_func_t _broadcast;
};


// Allocate memory for the peer and initialize it
peer_t *peer_malloc(uint16_t port, uint8_t ipType, uint8_t ipAtIndex, size_t maxConnections){
  peer_t * out = malloc(sizeof(peer_t));
  out->_port = port;
  out->_peerIP = ip_getIP(ipType,ipAtIndex);
  out->_peerList = vector_malloc(sizeof(peerConnection_t), maxConnections);
  return out;
}

// Free resources associated with the peer
void peer_free(peer_t *out){
  ip_freeIP(out->_peerIP);
  free_vector(out->_peerList);
  free(out);
}

// Set thee listening function
void peer_set_listen_func(peer_t * out, peer_listen_func_t function){
  out->_listen = function;
}

// Set thee broadcasting function
void peer_set_broadcast_func(peer_t * out, peer_broadcast_func_t function){
  out->_broadcast = function;
}

uint16_t peer_getPort(peer_t * out){
  return out->_port;
}
size_t peer_getPeerCount(peer_t * out){
  return vector_getCount(out->_peerList);
}

int peer_Broadcast(peer_t *out, const void *data, size_t dataLength) {
    if (out->_broadcast != NULL) {
        out->_broadcast(out, data, dataLength);
        return PEER_E_SUCCESS;
    }
    return PEER_E_INVALID_BROADCAST;
}
