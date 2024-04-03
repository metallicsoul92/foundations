#include "../../include/net/netEventHandler.h"

// User-defined function structure
struct userFunction {
    uint16_t _identifier;     // Unique identifier for the function
    void (*_function)(void*); // Pointer to the user-defined function
    void *_userData;         // User data associated with the function
};

// Event handler structure
struct netEventHandler_t {
    size_t _eventCount; // Number of registered user functions
    vector_t _events;   // Vector to store user functions
};

// Allocate memory for a user function and initialize it
userFunction_t *userFunction_malloc(uint16_t id, void (*func)(void*), void *userData) {
    userFunction_t *out = malloc(sizeof(userFunction_t));
    if (out != NULL) {
        out->_identifier = id;
        out->_function = func;
        out->_userData = userData;
    }
    return out;
}

// Free resources associated with a user function
void userFunction_free(userFunction_t *out) {
    free(out);
}

// Get the identifier of a user function
uint16_t userFunction_getID(userFunction_t *function) {
    return function->_identifier;
}

// Get the function pointer of a user function
void (*userFunction_getFunction(userFunction_t *function))(void*) {
    return function->_function;
}

// Get the user data associated with a user function
void *userFunction_getUserData(userFunction_t *function) {
    return function->_userData;
}

// Register a user function in the event handler
void register_user_function(netEventHandler_t *handler, userFunction_t *function) {
    vector_push(handler->_events, function);
    handler->_eventCount++;
}

// Process an event with the specified event ID
void process_event(netEventHandler_t *handler, uint16_t event_id) {
    // Iterate over registered user functions and call the relevant ones based on event_id.
    for (size_t i = 0; i < handler->_eventCount; i++) {
        userFunction_t *function = vector_get(handler->_events, i);
        if (function->_identifier == event_id) {
            // Call the user function with user data.
            function->_function(function->_userData);
        }
    }
}
