#include  "../../include/net/netEventHandler.h"

struct userFunction {
    uint16_t _identifier;
    void (*_function)(void*);
    void *_userData;
} ;

struct netEventHandler_t{
  size_t _eventCount;
  vector_t _events;
};

uint16_t userFunction_getID(userFunction_t * function){
  return function->_identifier;
}
void * userFunction_getFunction(userFunction_t * function){
  return function->_function(function->_userData);
}
void * userFunction_getUserData(userFunction_t * function){
  return  function->_userData;
}

void register_user_function(netEventHandler_t * handler, userFunction_t *function){
  vector_push(handler->_events,function);
}
void process_event(struct netEventHandler_t *handler, uint16_t event_id) {
    // Iterate over registered user functions and call the relevant ones based on event_id.
    for (size_t i = 0; i < handler->_eventCount; i++) {
        struct userFunction *function = vector_get(handler->_events, i);
        if (function->_identifier == event_id) {
            // Call the user function with user data.
            function->_function(function->_userData);
        }
    }
}
