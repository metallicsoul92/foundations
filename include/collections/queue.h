#ifndef FOUNDATIONS_COLLECTIONS_QUEUE_H_
#define FOUNDATIONS_COLLECTIONS_QUEUE_H_



#ifndef STDDEF_DEFINED
#include <stddef.h>
#define STDDEF_DEFINED 1
#endif

// Opaque pointer to the queue_t structure (hides the implementation details)
typedef struct queue* queue_t;

// Function to create a new empty queue_t
queue_t queue_malloc(void);

// Function to check if the queue_t is empty
int queue_is_empty(queue_t queue_t);

// Function to get the size of the queue_t
size_t queue_size(queue_t queue_t);

// Function to enqueue_t an element
int queue_enqueue_t(queue_t queue_t, int value);

// Function to dequeue_t an element
int queue_dequeue_t(queue_t queue_t);

// Function to get the front element without dequeuing
int queue_peek(queue_t queue_t);

// Function to free the queue_t
void queue_free(queue_t queue_t);

#endif
