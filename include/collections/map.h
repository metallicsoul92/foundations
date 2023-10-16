#ifndef FOUNDATIONS_CORE_MAP_H_
#define FOUNDATIONS_CORE_MAP_H_ 1

#ifndef STDDEF_DEFINED
#include <stddef.h>
#define STDDEF_DEFINED 1
#endif

typedef struct map map_t;
//initializing an already allocated map.
void map_init(map_t *m, size_t initialCapacity);
//allocating a new map
map_t * map_malloc(size_t initialCapazity);
//allocating a new map and copying the contents of the parameter
map_t * map_copy(const map_t * copy);
//allocating a new map and moving the contents of the parameter
map_t * map_move(map_t * move);
//insert a new key value pair
void map_insert(map_t *m, const char *key, const char *value);
//find the value at a key in a map
const char *map_find(const map_t *m, const char *key);
//clear the map
void map_clear(map_t *m);
//map free
void map_free(map_t * m);
//get size
size_t map_getSize(map_t *m);
//get capacity
size_t map_getCapacity(map_t * m);



#endif
