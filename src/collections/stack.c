#include "../../include/collections/stack.h"
#include <stdio.h>
#include <stdlib.h>

struct stack_node{
  void * data;
  struct stack_node *_next;
};

typedef struct stack_node stack_node_t;

struct stack{
  size_t _ElementSize;
  size_t _ElementCount;
  size_t _ElementCapacity;
  struct stack_node * _ElementData;
};


stack_t *stack_malloc(size_t capacity, size_t elemSize) {
    stack_t *stack = (stack_t *)malloc(sizeof(stack_t));
    if (stack == NULL) {
        fprintf(stderr, "Memory allocation error for stack creation\n");
        return NULL;
    }

    stack->_ElementSize = elemSize;  // Fix the parameter name
    stack->_ElementCapacity = capacity;
    stack->_ElementCount = 0;
    stack->_ElementData = NULL;  // Initialize the stack with no elements (NULL head)

    return stack;
}

void stack_free(stack_t *stack) {
    while (!stack_is_empty(stack)) {
        void *element;
        stack_pop(stack, &element);
        // You might want to release any resources associated with the element here.
    }

    free(stack); // Free the memory for the stack itself
}


// Function to push an element onto the stack
int stack_push(stack_t *stack, void *element) {
    if (stack == NULL || stack->_ElementCount >= stack->_ElementCapacity) {
        fprintf(stderr, "Invalid stack or stack is full\n");
        return -1; // Error
    }

    stack_node_t *new_node = (stack_node_t *)malloc(sizeof(stack_node_t));
    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation error for stack push\n");
        return -1; // Error
    }

    new_node->data = element;
    new_node->_next = stack->_ElementData;
    stack->_ElementData = new_node;
    stack->_ElementCount++;

    return 0; // Success
}

// Function to pop an element from the stack
int stack_pop(stack_t *stack, void **element) {
    if (stack == NULL || stack->_ElementCount == 0) {
        fprintf(stderr, "Invalid stack or stack is empty\n");
        return -1; // Error
    }

    stack_node_t *top_node = stack->_ElementData;
    *element = top_node->data;
    stack->_ElementData = top_node->_next;
    free(top_node);
    stack->_ElementCount--;

    return 0; // Success
}

// Function to check if the stack is empty
int stack_is_empty(stack_t *stack) {
    return (stack == NULL || stack->_ElementCount == 0);
}
