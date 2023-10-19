/**
 * @file allocator.h
 * @brief A custom memory allocator library for C with support for thread safety.
 *
 * This library provides basic memory allocation and deallocation functionalities,
 * along with support for customizable initial sizes upon creation. It includes
 * thread-safe operations and allows for static and dynamic allocation from specified
 * or the current allocator.
 *
 * @author Clim Jark
 * @version 1.0
 */

#ifndef FOUNDATIONS_CORE_ALLOCATOR_H_
#define FOUNDATIONS_CORE_ALLOCATOR_H_

// Include necessary standard headers and forward declarations.

// Forward declare fixed data types if not already defined.
#ifndef STDINT_DEFINED
#include <stdint.h>
#define STDINT_DEFINED 1
#endif

#ifndef STDDEF_DEFINED
#include <stddef.h>
#define STDDEF_DEFINED 1
#endif

/** @def ALLOC_SUCCESS
 *  The allocation operation was successful.
 */
#define ALLOC_SUCCESS 0

/** @def ALLOC_NOMEM
 *  The allocation operation failed due to insufficient memory.
 */
#define ALLOC_NOMEM 1

/** @def ALLOC_BINFAIL
 *  Binary allocation operation failure flag (internal use).
 */
#define ALLOC_BINFAIL 16

/** @def ALLOCATOR_DEFINED
 *  A macro flag indicating that the allocator structure is defined.
 */
#ifndef ALLOCATOR_DEFINED
typedef struct _allocator allocator_t;
#define ALLOCATOR_DEFINED 1
#endif

/**
 * @brief Initializes an allocator with specified options.
 *
 * @param allocator Pointer to the allocator structure to be initialized.
 * @return 0 on success, 1 on memory allocation failure.
 */
uint8_t allocator_init(allocator_t * allocator);

/**
 * @brief Initializes the static allocator with default options.
 *
 * @return 0 on success, 1 on memory allocation failure.
 */
uint8_t static_allocator_init();

/**
 * @brief Destroys the specified allocator, releasing associated resources.
 *
 * @param self Pointer to the allocator structure to be destroyed.
 */
void allocator_destroy(allocator_t * self);

/**
 * @brief Sets the current allocator for static allocation functions.
 *
 * @param alloc Pointer to the allocator to be set as the current allocator.
 */
void static_set_allocator(allocator_t * alloc);

/**
 * @brief Allocates memory from the current allocator.
 *
 * @param size Size of memory to allocate.
 * @return Pointer to the allocated memory on success, NULL on memory allocation failure.
 */
void * static_allocator_malloc(size_t size);

/**
 * @brief Allocates memory from the current allocator and initializes it with zeros.
 *
 * @param size Size of memory to allocate.
 * @return Pointer to the allocated memory on success, NULL on memory allocation failure.
 */
void * static_allocator_calloc(size_t size);

/**
 * @brief Reallocates memory from the current allocator.
 *
 * @param address Pointer to the memory to reallocate.
 * @param size    New size of memory.
 * @return Pointer to the reallocated memory on success, NULL on memory allocation failure.
 */
void * static_allocator_realloc(void * address, size_t size);

/**
 * @brief Allocates memory from the specified allocator.
 *
 * @param allocator Pointer to the allocator to use for allocation.
 * @param size      Size of memory to allocate.
 * @return Pointer to the allocated memory on success, NULL on memory allocation failure.
 */
void * allocator_malloc(allocator_t * allocator, size_t size);

/**
 * @brief Allocates memory from the specified allocator and initializes it with zeros.
 *
 * @param allocator Pointer to the allocator to use for allocation.
 * @param size      Size of memory to allocate.
 * @return Pointer to the allocated memory on success, NULL on memory allocation failure.
 */
void * allocator_calloc(allocator_t * allocator, size_t size);

/**
 * @brief Reallocates memory from the specified allocator.
 *
 * @param allocator Pointer to the allocator to use for reallocation.
 * @param address   Pointer to the memory to reallocate.
 * @param size      New size of memory.
 * @return Pointer to the reallocated memory on success, NULL on memory allocation failure.
 */
void * allocator_realloc(allocator_t * allocator, void * address, size_t size);

/**
 * @brief Frees memory allocated within the static allocator.
 *
 * @param address Pointer to the memory to be freed.
 */
void static_allocator_free(void * address);

/**
 * @brief Frees memory allocated within the specified allocator.
 *
 * @param self    Pointer to the allocator to use for deallocation.
 * @param address Pointer to the memory to be freed.
 */
void allocator_free(allocator_t * self, void * address);

#endif
