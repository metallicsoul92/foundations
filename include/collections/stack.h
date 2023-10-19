/**
 * @file stack.h
 * @brief A custom stack library for C.
 *
 * This library provides a basic implementation of a stack data structure for C. A stack is a linear data structure that follows the Last-In, First-Out (LIFO) order, where elements are added and removed from the same end. This library allows you to create, manipulate, and free stacks. It provides functions to create, push, pop elements, and check the status of the stack.
 *
 * @author Clim Jark
 * @version 1.0
 */

#ifndef FOUNDATIONS_COLLECTIONS_STACK_H_
#define FOUNDATIONS_COLLECTIONS_STACK_H_

/**
 * @typedef stack_t
 * Opaque pointer to the stack structure (hides the implementation details).
 */
typedef struct stack stack_t;

#ifndef STDDEF_DEFINED
#include <stddef.h>
#define STDDEF_DEFINED 1
#endif

/**
 * @brief Allocates a new stack with the specified capacity and element size.
 *
 * @param capacity The maximum number of elements the stack can hold.
 * @param elemSize The size of each element in bytes.
 * @return A pointer to the newly allocated stack on success, or NULL on memory allocation failure.
 */
stack_t *stack_malloc(size_t capacity, size_t elemSize);

/**
 * @brief Frees the memory used by the stack and all its elements.
 *
 * @param stack The stack to be freed.
 */
void stack_free(stack_t *stack);

/**
 * @brief Pushes an element onto the stack.
 *
 * @param stack The stack to push the element onto.
 * @param element A pointer to the element to be pushed.
 * @return 0 on success, or a non-zero value on failure (e.g., stack is full).
 */
int stack_push(stack_t *stack, void *element);

/**
 * @brief Pops an element from the stack.
 *
 * @param stack The stack to pop from.
 * @param element A pointer to a pointer where the popped element will be stored.
 * @return 0 on success, or a non-zero value on failure (e.g., stack is empty).
 */
int stack_pop(stack_t *stack, void **element);

/**
 * @brief Checks if the stack is empty.
 *
 * @param stack The stack to check.
 * @return 1 if the stack is empty, 0 if it contains elements.
 */
int stack_is_empty(stack_t *stack);

#endif
