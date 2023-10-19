/**
 * @file queue.h
 * @brief A custom queue library for C.
 *
 * This library provides a basic implementation of a queue data structure for C. A queue is a linear data structure that follows the FIFO (First-In-First-Out) principle. It allows you to create and manage a queue of integer values. The library provides functions to create, manipulate, and free queues, as well as enqueue and dequeue elements.
 *
 * @author Clim Jark
 * @version 1.0
 */

#ifndef FOUNDATIONS_COLLECTIONS_QUEUE_H_
#define FOUNDATIONS_COLLECTIONS_QUEUE_H_

// Include necessary standard headers and forward declarations.

#ifndef STDDEF_DEFINED
#include <stddef.h>
#define STDDEF_DEFINED 1
#endif

/**
 * @typedef queue_t
 * Opaque pointer to the queue structure (hides the implementation details).
 */
typedef struct queue* queue_t;

/**
 * @brief Creates a new empty queue.
 *
 * @return A pointer to the newly created empty queue on success, or NULL on memory allocation failure.
 */
queue_t queue_malloc(void);

/**
 * @brief Checks if the queue is empty.
 *
 * @param queue_t The queue to check.
 * @return 1 if the queue is empty, 0 otherwise.
 */
int queue_is_empty(queue_t queue_t);

/**
 * @brief Gets the size of the queue.
 *
 * @param queue_t The queue to query.
 * @return The number of elements in the queue.
 */
size_t queue_size(queue_t queue_t);

/**
 * @brief Enqueues an element into the queue.
 *
 * @param queue_t The queue to enqueue into.
 * @param value The value to enqueue.
 * @return 0 on successful enqueue, or -1 if the queue is full.
 */
int queue_enqueue_t(queue_t queue_t, int value);

/**
 * @brief Dequeues an element from the queue.
 *
 * @param queue_t The queue to dequeue from.
 * @return The dequeued value on success, or -1 if the queue is empty.
 */
int queue_dequeue_t(queue_t queue_t);

/**
 * @brief Gets the front element of the queue without dequeuing it.
 *
 * @param queue_t The queue to peek into.
 * @return The front element of the queue on success, or -1 if the queue is empty.
 */
int queue_peek(queue_t queue_t);

/**
 * @brief Frees the memory used by the queue.
 *
 * @param queue_t The queue to be freed.
 */
void queue_free(queue_t queue_t);

#endif
