#ifndef FOUNDATIONS_COLLECTIONS_STACK_H_
#define FOUNDATIONS_COLLECTIONS_STACK_H_ 1

typedef struct stack stack_t;

#ifndef STDDEF_DEFINED
#include <stddef.h>
#define STDDEF_DEFINED 1
#endif

//allocate a stack
stack_t *stack_malloc(size_t capacity, size_t elemSize);

//free a stack
void stack_free(stack_t *stack);

// Function to push an element onto the stack
int stack_push(stack_t *stack, void *element);

// Function to pop an element from the stack
int stack_pop(stack_t *stack, void **element);


// Function to check if the stack is empty
int stack_is_empty(stack_t *stack);


#endif
