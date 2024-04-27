/**
 * @file vector.h
 * @brief A custom dynamic array (vector) library for C.
 *
 * This library provides a basic implementation of a dynamic array (vector) data structure in C. A dynamic array is a resizable array that can grow as elements are added. This library allows you to create, manipulate, and free dynamic arrays. It provides functions for allocating memory, setting properties, and working with dynamic arrays.
 *
 * @author Clim Jark
 * @version 1.0
 */

#ifndef FOUNDATIONS_CORE_VECTOR_H_
#define FOUNDATIONS_CORE_VECTOR_H_

#ifndef STDINT_DEFINED
#include <stdint.h>
#define STDINT_DEFINED 1
#endif

#ifndef STDDEF_DEFINED
#include <stddef.h>
#define STDDEF_DEFINED 1
#endif

/**
 * @def VEC_FLAG_NONE
 * Flag indicating no errors or special conditions.
 */
#define VEC_FLAG_NONE 0

/**
 * @def VEC_FLAG_EMPTY
 * Flag indicating that `vector_pop` was used on an empty vector.
 */
#define VEC_FLAG_EMPTY 1

/**
 * @def VEC_FLAG_FULL
 * Flag indicating that `vector_push` was used on a full vector.
 */
#define VEC_FLAG_FULL 2

/**
 * @def VEC_FLAG_INVALID_RESIZE
 * Flag indicating an attempt to resize to a lower capacity with elements in the way.
 */
#define VEC_FLAG_INVALID_RESIZE 3

/**
 * @typedef vector_t
 * Opaque pointer to the vector structure (hides the implementation details).
 */

 #ifndef VECTOR_DEF
 typedef struct vector vector_t;
 #define VECTOR_DEF
 #endif


/**
 * @brief Retrieves the size of a vector.
 *
 * @param out The vector.
 * @return The size of the vector.
 */
size_t vector_getSize(vector_t *out);

/**
 * @brief Retrieves the capacity of a vector.
 *
 * @param out The vector.
 * @return The capacity of the vector.
 */
size_t vector_getCapacity(vector_t *out);

/**
 * @brief Retrieves the number of elements in a vector.
 *
 * @param out The vector.
 * @return The count of elements in the vector.
 */
size_t vector_getCount(vector_t *out);

/**
 * @brief Retrieves the error flag of a vector, indicating special conditions.
 *
 * @param out The vector.
 * @return The error flag of the vector.
 */
uint8_t vector_eFlag(vector_t *out);

/**
 * @brief Retrieves an element in the vector at the specified index.
 *
 * @param out The vector.
 * @param index The index of the element to retrieve.
 * @return A pointer to the element in the vector at the given index.
 */
void *vector_getElementAt(vector_t *out, size_t index);

/**
 * @brief Retrieves the raw data of a vector.
 *
 * This function returns the starting address of the vector's data.
 *
 * @param out The vector.
 * @return A pointer to the raw data of the vector.
 */
void *vector_getRawData(vector_t *out);

/**
 * @brief Allocates a new vector with the specified element size and initial capacity.
 *
 * @param size The element size of the vector.
 * @param capacity The initial capacity of the vector.
 * @return A pointer to the newly allocated vector.
 */
vector_t *vector_malloc(size_t size, size_t capacity);

/**
 * @brief Initializes an existing vector with the specified element size and initial capacity.
 *
 * @param out The vector to be initialized.
 * @param size The element size of the vector.
 * @param capacity The initial capacity of the vector.
 * @return A pointer to the initialized vector.
 */
vector_t *vector_init(vector_t *out, size_t size, size_t capacity);

/**
 * @brief Allocates a new vector by copying the contents of an existing vector.
 *
 * @param copy The vector to be copied.
 * @return A pointer to the newly allocated vector.
 */
vector_t *vector_copy(const vector_t *copy);

/**
 * @brief Allocates a new vector by moving the contents of an existing vector.
 *
 * @param move The vector to be moved.
 * @return A pointer to the newly allocated vector.
 */
vector_t *vector_move(vector_t *move);

/**
 * @brief Frees the memory used by a vector and its elements.
 *
 * @param out The vector to be freed.
 */
void free_vector(vector_t *out);

/**
 * @brief Empties a vector, removing all elements.
 *
 * @param out The vector to be emptied.
 */
void vector_empty(vector_t *out);

/**
 * @brief Pushes an element onto a vector.
 *
 * @param out The vector.
 * @param element A pointer to the element to be added to the vector.
 */
void vector_push(vector_t *out, void *element);

/**
 * @brief Pops an element from the end of a vector.
 *
 * @param out The vector.
 * @return A pointer to the popped element.
 */
void *vector_pop(vector_t *out);

/**
 * @brief Resizes a vector to accommodate additional elements.
 *
 * @param out The vector to be resized.
 */
void vector_resize(vector_t *out);

/**
 * @brief Resizes a vector to the exact specified new capacity.
 *
 * @param out The vector to be resized.
 * @param newCap The new capacity to set.
 */
void vector_exactResize(vector_t *out, size_t newCap);

#endif
