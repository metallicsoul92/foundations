#ifndef MAP_C_
#define MAP_C_

#include <stdlib.h>
#include <string.h>
#include "../../include/collections/priv/types.h"
#include "../../include/collections/kvpair.h"
#include "../../include/collections/map.h"



// Define the map structure
struct map {
    kvpair_t *pairs;
    size_t size;
    size_t capacity;
};

// Initialize an already allocated map
void map_init(map_t *m, size_t initialCapacity) {
    m->pairs = malloc(initialCapacity * static_kvpair_size());
    m->size = 0;
    m->capacity = initialCapacity;
}

// Allocate a new map
map_t *map_malloc(size_t initialCapacity) {
    map_t *m = malloc(sizeof(map_t));
    if (m) {
        map_init(m, initialCapacity);
    }
    return m;
}

// Allocate a new map and copy the contents of the parameter
map_t *map_copy(const map_t *copy) {
    map_t *m = map_malloc(copy->capacity);
    if (m) {
        for (size_t i = 0; i < copy->size; i++) {
            map_insert(m, kvpair_getKey(&copy->pairs[i]),kvpair_getValue(&copy->pairs[i]));
        }
    }
    return m;
}

// Allocate a new map and move the contents of the parameter
map_t *map_move(map_t *move) {
    map_t *m = malloc(sizeof(map_t));
    if (m) {
        m->pairs = move->pairs;
        m->size = move->size;
        m->capacity = move->capacity;

        move->pairs = NULL;
        move->size = 0;
        move->capacity = 0;
    }
    return m;
}

// Insert a new key-value pair into the map
void map_insert(map_t *m, const char *key, const char *value) {
    if (m->size == m->capacity) {
        // Resize the vector if it's full
        m->capacity *= 2;
        m->pairs = realloc(m->pairs, m->capacity * static_kvpair_size());
    }

    // Create a new kvpair and set its key and value
    kvpair_t *newPair = kvpair_malloc(key, value);

    // Check if the allocation was successful
    if (newPair) {
        m->pairs[m->size] = *newPair;
        free(newPair);  // Free the temporary kvpair
        m->size++;
    }
}

// Find a value by key
const char *map_find(const map_t *m, const char *key) {
    for (size_t i = 0; i < m->size; i++) {
        if (strcmp(kvpair_getKey(&m->pairs[i]), key) == 0) {
            return kvpair_getValue(&m->pairs[i]);
        }
    }
    return NULL; // Key not found
}

// Clear the map
void map_clear(map_t *m) {
    for (size_t i = 0; i < m->size; i++) {
        kvpair_free(&m->pairs[i]);
    }
    free(m->pairs);
    m->size = 0;
    m->capacity = 0;
}

// Free resources and clear the map
void map_free(map_t *m) {
    if (m) {
        map_clear(m);
        free(m);
    }
}

//get size
size_t map_getSize(map_t *m){
  return m->size;
}
//get capacity
size_t map_getCapacity(map_t * m){
  return m->capacity;
}

#endif // MAP_C_
