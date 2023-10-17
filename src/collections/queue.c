#include <stdio.h>
#include <stdlib.h>
#include "../../include/collections/queue.h"

// Define the queue structure
struct queue {
    int* elements;
    size_t front;
    size_t rear;
    size_t size;
    size_t capacity;
};

// Function to create a new empty queue
queue_t queue_malloc(void) {
    queue_t queue = (queue_t)malloc(sizeof(struct queue));
    if (queue == NULL) {
        return NULL;
    }
    queue->elements = (int*)malloc(sizeof(int) * 100); // Initial capacity of 100
    if (queue->elements == NULL) {
        free(queue);
        return NULL;
    }
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
    queue->capacity = 100;
    return queue;
}

// Function to check if the queue is empty
int queue_is_empty(queue_t queue) {
    return queue->size == 0;
}

// Function to get the size of the queue
size_t queue_size(queue_t queue) {
    return queue->size;
}

// Function to resize the queue if needed
static int resize_queue(queue_t queue) {
    if (queue->size == queue->capacity) {
        queue->capacity *= 2;
        int* new_elements = (int*)malloc(sizeof(int) * queue->capacity);
        if (new_elements == NULL) {
            return 0;
        }
        for (size_t i = 0; i < queue->size; i++) {
            new_elements[i] = queue->elements[(queue->front + i) % queue->capacity];
        }
        free(queue->elements);
        queue->elements = new_elements;
        queue->front = 0;
        queue->rear = queue->size - 1;
    }
    return 1;
}

// Function to enqueue an element
int queue_enqueue(queue_t queue, int value) {
    if (!resize_queue(queue)) {
        return 0;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->elements[queue->rear] = value;
    queue->size++;
    return 1;
}

// Function to dequeue an element
int queue_dequeue(queue_t queue) {
    if (queue->size == 0) {
        // queue_t is empty
        return -1;
    }
    int value = queue->elements[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return value;
}

// Function to get the front element without dequeuing
int queue_peek(queue_t queue) {
    if (queue->size == 0) {
        // queue_t is empty
        return -1;
    }
    return queue->elements[queue->front];
}

// Function to free the queue
void queue_free(queue_t queue) {
    if (queue != NULL) {
        free(queue->elements);
        free(queue);
    }
}
