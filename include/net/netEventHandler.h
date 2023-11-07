#ifndef FOUNDATIONS_NET_NETEVENTHANDLER_H_
#define FOUNDATIONS_NET_NETEVENTHANDLER_H_

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

typedef struct userFunction userFunction_t;
typedef struct netEventHandler netEventHandler_t;

uint16_t userFunction_getID(userFunction_t * function);
void * userFunction_getFunction(userFunction_t * function);
void * userFunction_getUserData(userFunction_t * function);

void register_user_function(user_function_t *function);
void process_event(uint16_t event_id);



#endif
