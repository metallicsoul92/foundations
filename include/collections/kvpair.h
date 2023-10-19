/**
 * @file kvpair.h
 * @brief A custom Key-Value Pair (KVPair) library for C.
 *
 * This library provides a basic implementation of a Key-Value Pair (KVPair)
 * data structure for C. It allows you to create key-value pairs with string
 * keys and string values, and provides functions to allocate, copy, move, and
 * manage these pairs.
 *
 * @author Clim Jark
 * @version 1.0
 */

#ifndef FOUNDATIONS_COLLECTIONS_KVPAIR_H_
#define FOUNDATIONS_COLLECTIONS_KVPAIR_H_ 1

// Include necessary standard headers and forward declarations.

#ifndef STDDEF_DEFINED
#include <stddef.h>
#define STDDEF_DEFINED 1
#endif

/** @def KVPAIR_DEFINED
 *  A macro flag indicating that the `kvpair` structure is defined.
 */
#ifndef KVPAIR_DEFINED
typedef struct kvpair kvpair_t;
#define KVPAIR_DEFINED 1
#endif

/**
 * @brief Allocates a Key-Value Pair with the given key and value.
 *
 * @param key   The key for the key-value pair.
 * @param value The value associated with the key.
 * @return A pointer to the newly created KVPair on success, NULL on memory allocation failure.
 */
kvpair_t * kvpair_malloc(const char * key, const char * value);

/**
 * @brief Allocates an empty Key-Value Pair, which can be modified later.
 *
 * @return A pointer to the newly created empty KVPair on success, NULL on memory allocation failure.
 */
kvpair_t * kvpair_malloc_empty();

/**
 * @brief Allocates a new Key-Value Pair that matches the content of an existing KVPair.
 *
 * @param copy The KVPair to be copied.
 * @return A pointer to the newly created KVPair on success, NULL on memory allocation failure.
 */
kvpair_t * kvpair_copy(const kvpair_t * copy);

/**
 * @brief Allocates a new Key-Value Pair and moves the contents of an existing KVPair to it.
 *
 * @param move The KVPair to be moved.
 * @return A pointer to the newly created KVPair on success, NULL on memory allocation failure.
 */
kvpair_t * kvpair_move(kvpair_t * move);

/**
 * @brief Frees a Key-Value Pair.
 *
 * @param obj Pointer to the KVPair to be freed.
 */
void kvpair_free(kvpair_t * obj);

/**
 * @brief Sets the key of a Key-Value Pair.
 *
 * @param obj Pointer to the KVPair.
 * @param key The key to set.
 */
void kvpair_setKey(kvpair_t * obj, const char * key);

/**
 * @brief Sets the value of a Key-Value Pair.
 *
 * @param obj   Pointer to the KVPair.
 * @param value The value to set.
 */
void kvpair_setValue(kvpair_t * obj, const char * value);

/**
 * @brief Gets the key of a Key-Value Pair.
 *
 * @param obj Pointer to the KVPair.
 * @return The key associated with the KVPair.
 */
const char * kvpair_getKey(const kvpair_t * obj);

/**
 * @brief Gets the value of a Key-Value Pair.
 *
 * @param obj Pointer to the KVPair.
 * @return The value associated with the KVPair.
 */
const char * kvpair_getValue(const kvpair_t * obj);

/**
 * @brief Retrieves the size of the `kvpair` structure.
 *
 * @return Size of the `kvpair` structure in bytes.
 */
size_t static_kvpair_size();

#endif
