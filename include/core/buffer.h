/**
 * @file buffer.h
 * @brief A custom buffer library for C.
 *
 * This library provides functionality for working with custom buffer structures.
 * Users can create, manipulate, and manage buffers using this library.
 * The library includes functions for memory allocation, deallocation,
 * reading data from the buffer, and writing data to the buffer.
 *
 * The custom buffer structure (`buffer_t`) is designed for efficient data storage
 * and retrieval, making it a suitable choice for various data manipulation tasks.
 *
 * @author Clim Jark
 * @version 1.0
 */

#ifndef FOUNDATIONS_CORE_BUFFER_H_
#define FOUNDATIONS_CORE_BUFFER_H_ 1

#ifndef STDDEF_DEFINED
#include <stddef.h>
#define STDDEF_DEFINED 1
#endif


/** @struct buffer
 *  @brief A custom buffer structure for C.
 *
 *  The `buffer` structure represents a custom buffer type that provides efficient
 *  data storage and retrieval.
 *
 *  @var buffer::_size
 *  The current size of the buffer.
 *
 *  @var buffer::_capacity
 *  The total capacity of the buffer.
 *
 *  @var buffer::_data
 *  A pointer to the memory where the buffer stores data.
 */
#ifndef BUFFER_T_DEF
typedef struct buffer buffer_t;
#define BUFFER_T_DEF 1
#endif
/** @brief Allocate memory for a new `buffer_t` and set its initial capacity.
 *
 *  @param capacity The initial capacity of the buffer.
 *  @return A pointer to the newly created `buffer_t`.
 */
buffer_t * buffer_malloc(size_t capacity);

/** @brief Deallocate memory used by a `buffer_t`.
 *
 *  @param buffer A pointer to the `buffer_t` to free.
 */
void buffer_free(buffer_t * buffer);

/** @brief Read data from a `buffer_t` into the provided buffer.
 *
 *  @param buffer A pointer to the `buffer_t` to read from.
 *  @param data A pointer to the destination buffer.
 *  @param length The number of bytes to read.
 *  @return The number of bytes actually read.
 */
size_t buffer_read(buffer_t* buffer, char* data, size_t length);

/** @brief Write data to a `buffer_t` from the provided source buffer.
 *
 *  @param buffer A pointer to the `buffer_t` to write to.
 *  @param data A pointer to the source buffer.
 *  @param length The number of bytes to write.
 *  @return The number of bytes actually written.
 */
size_t buffer_write(buffer_t* buffer, const char* data, size_t length);

#endif
