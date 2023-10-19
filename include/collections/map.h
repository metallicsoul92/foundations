/**
 * @file map.h
 * @brief A custom map (dictionary) library for C.
 *
 * This library provides a basic implementation of a map (dictionary) data structure for C. It allows you to create and manage key-value pairs, where both the keys and values are strings. The map can dynamically resize as needed, and it provides functions to insert, find, clear, and manage key-value pairs.
 *
 * @author Clim Jark
 * @version 1.0
 */

#ifndef FOUNDATIONS_CORE_MAP_H_
#define FOUNDATIONS_CORE_MAP_H_ 1

// Include necessary standard headers and forward declarations.

#ifndef STDDEF_DEFINED
#include <stddef.h>
#define STDDEF_DEFINED 1
#endif

/** @def MAP_DEFINED
 *  A macro flag indicating that the `map` structure is defined.
 */
#ifndef MAP_DEFINED
typedef struct map map_t;
#define MAP_DEFINED 1
#endif

/**
 * @brief Initializes an already allocated map with the specified initial capacity.
 *
 * @param m             Pointer to the map structure to be initialized.
 * @param initialCapacity Initial capacity for the map.
 */
void map_init(map_t *m, size_t initialCapacity);

/**
 * @brief Allocates a new map with the specified initial capacity.
 *
 * @param initialCapacity Initial capacity for the map.
 * @return A pointer to the newly created map on success, NULL on memory allocation failure.
 */
map_t * map_malloc(size_t initialCapacity);

/**
 * @brief Allocates a new map and copies the contents of the provided map.
 *
 * @param copy The map to be copied.
 * @return A pointer to the newly created map with copied contents on success, NULL on memory allocation failure.
 */
map_t * map_copy(const map_t * copy);

/**
 * @brief Allocates a new map and moves the contents of the provided map.
 *
 * @param move The map to be moved.
 * @return A pointer to the newly created map with moved contents on success, NULL on memory allocation failure.
 */
map_t * map_move(map_t * move);

/**
 * @brief Inserts a new key-value pair into the map.
 *
 * @param m   Pointer to the map.
 * @param key The key for the key-value pair.
 * @param value The value associated with the key.
 */
void map_insert(map_t *m, const char *key, const char *value);

/**
 * @brief Finds the value associated with a given key in the map.
 *
 * @param m   Pointer to the map.
 * @param key The key to search for.
 * @return The value associated with the key if found, or NULL if the key is not present in the map.
 */
const char *map_find(const map_t *m, const char *key);

/**
 * @brief Clears all key-value pairs in the map.
 *
 * @param m Pointer to the map.
 */
void map_clear(map_t *m);

/**
 * @brief Frees the memory used by the map.
 *
 * @param m Pointer to the map to be freed.
 */
void map_free(map_t * m);

/**
 * @brief Gets the current size (number of key-value pairs) in the map.
 *
 * @param m Pointer to the map.
 * @return The number of key-value pairs in the map.
 */
size_t map_getSize(map_t *m);

/**
 * @brief Gets the current capacity (maximum number of key-value pairs that can be stored) of the map.
 *
 * @param m Pointer to the map.
 * @return The capacity of the map.
 */
size_t map_getCapacity(map_t * m);

#endif
