#ifndef FOUNDATIONS_CORE_BUFFER_H_
#define FOUNDATIONS_CORE_BUFFER_H_ 1


#ifndef STDDEF_DEFINED
#include <stddef.h>
#define STDDEF_DEFINED 1
#endif

typedef struct buffer buffer_t;


//Memory allocation and deallocation
buffer_t * buffer_malloc(size_t capacity);
void buffer_free(buffer_t * buffer);

// Read data from the buffer
size_t buffer_read(buffer_t* buffer, char* data, size_t length);

// Write data to the buffer
size_t buffer_write(buffer_t* buffer, const char* data, size_t length);

#endif
