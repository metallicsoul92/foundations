#ifndef FOUNDATIONS_NET_NETEVENTHANDLER_H_
#define FOUNDATIONS_NET_NETEVENTHANDLER_H_ 1

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

// Define the user function structure as 'userFunction_t'
typedef struct userFunction userFunction_t;
// Define the net event handler structure as 'netEventHandler_t'
typedef struct netEventHandler netEventHandler_t;

// Get the identifier of a user function
uint16_t userFunction_getID(userFunction_t *function);

// Get the function pointer of a user function
void *userFunction_getFunction(userFunction_t *function);

// Get the user data associated with a user function
void *userFunction_getUserData(userFunction_t *function);

// Register a user function in the event handler
void register_user_function(userFunction_t *function);

// Process an event with the specified event ID
void process_event(uint16_t event_id);

#endif // FOUNDATIONS_NET_NETEVENTHANDLER_H_
