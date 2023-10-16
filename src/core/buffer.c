#include "../../include/core/buffer.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent the buffer
struct buffer {
    char* data;
    size_t size;
    size_t capacity;
};

// Initialize a buffer with a given capacity
buffer_t * buffer_malloc(size_t capacity) {
    buffer_t* buffer = (buffer_t*)malloc(sizeof(buffer_t));
    if (buffer) {
        buffer->data = (char*)malloc(capacity);
        if (buffer->data) {
            buffer->size = 0;
            buffer->capacity = capacity;
        } else {
            free(buffer);
            buffer = NULL;
        }
    }
    return buffer;
}

// Write data to the buffer
size_t buffer_write(buffer_t* buffer, const char* data, size_t length) {
    size_t available_space = buffer->capacity - buffer->size;
    size_t bytes_to_write = (length < available_space) ? length : available_space;
    memcpy(buffer->data + buffer->size, data, bytes_to_write);
    buffer->size += bytes_to_write;
    return bytes_to_write;
}

// Read data from the buffer
size_t buffer_read(buffer_t* buffer, char* data, size_t length) {
    size_t bytes_to_read = (length < buffer->size) ? length : buffer->size;
    memcpy(data, buffer->data, bytes_to_read);
    // Shift the remaining data to the beginning of the buffer
    memmove(buffer->data, buffer->data + bytes_to_read, buffer->size - bytes_to_read);
    buffer->size -= bytes_to_read;
    return bytes_to_read;
}

// Free the buffer and its data
void buffer_free(buffer_t* buffer) {
    if (buffer) {
        free(buffer->data);
        free(buffer);
    }
}
