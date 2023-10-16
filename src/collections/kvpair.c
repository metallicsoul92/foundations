#include <stdlib.h>
#include <string.h>
#include "../../include/collections/kvpair.h"
// Define the kvpair structure
struct kvpair {
    char *key;
    char *value;
};

// Allocate a new kvpair_t with the provided key and value
kvpair_t *kvpair_malloc(const char *key, const char *value) {
    kvpair_t *pair = (kvpair_t *)malloc(sizeof(kvpair_t));
    if (pair == NULL) {
        return NULL; // Memory allocation error
    }

    pair->key = strdup(key);
    pair->value = strdup(value);

    return pair;
}

// Allocate an empty kvpair_t to modify later
kvpair_t *kvpair_malloc_empty() {
    kvpair_t *pair = (kvpair_t *)malloc(sizeof(kvpair_t));
    if (pair == NULL) {
        return NULL; // Memory allocation error
    }

    pair->key = NULL;
    pair->value = NULL;

    return pair;
}

// Allocate a new kvpair_t to match an already created key-value pair
kvpair_t *kvpair_copy(const kvpair_t *copy) {
    kvpair_t *pair = kvpair_malloc_empty();
    if (pair == NULL) {
        return NULL; // Memory allocation error
    }

    if (copy->key) {
        pair->key = strdup(copy->key);
    }
    if (copy->value) {
        pair->value = strdup(copy->value);
    }

    return pair;
}

// Allocate a new kvpair_t and move the contents of an already created kvpair_t
kvpair_t *kvpair_move(kvpair_t *move) {
    kvpair_t *pair = kvpair_malloc_empty();
    if (pair == NULL) {
        return NULL; // Memory allocation error
    }

    pair->key = move->key;
    pair->value = move->value;

    move->key = NULL;
    move->value = NULL;

    return pair;
}

// Free the kvpair_t
void kvpair_free(kvpair_t *obj) {
    if (obj) {
        free(obj->key);
        free(obj->value);
        free(obj);
    }
}

// Set the key
void kvpair_setKey(kvpair_t *obj, const char *key) {
    free(obj->key);
    obj->key = strdup(key);
}

// Set the value
void kvpair_setValue(kvpair_t *obj, const char *value) {
    free(obj->value);
    obj->value = strdup(value);
}

// Get the key
const char *kvpair_getKey(const kvpair_t *obj) {
    return obj->key;
}

// Get the value
const char *kvpair_getValue(const kvpair_t *obj) {
    return obj->value;
}
//static function, get the size of the structure without exposing the implementation
size_t static_kvpair_size(){
    return (size_t)(sizeof(char *) + sizeof(char *));
}
