#ifndef FOUNDATIONS_COLLECTIONS_KVPAIR_H_
#define FOUNDATIONS_COLLECTIONS_KVPAIR_H_ 1

#ifndef STDDEF_DEFINED
#include <stddef.h>
#define STDDEF_DEFINED 1
#endif

#ifndef KVPAIR_DEFINED
typedef struct kvpair kvpair_t;
#define KVPAIR_DEFINED 1
#endif


//Allocate Key-Value Pair with its Key and Value
kvpair_t * kvpair_malloc(const char * key, const char * value);
//Allocate an empty Key-Value Pair to modify later
kvpair_t * kvpair_malloc_empty();
//Allocate a new Key-Value Pair to match an alredy created Key Value Pair
kvpair_t * kvpair_copy(const kvpair_t * copy);
//Allocate a new Key-Value Pair and move the contents of an already created Key
//Value Pair to the newly allocated Key Value Pair
kvpair_t * kvpair_move(kvpair_t * move);
//free the Key Value Pair
void kvpair_free(kvpair_t * obj);

//set Key
void kvpair_setKey(kvpair_t * obj, const char * key);
//set Value
void kvpair_setValue(kvpair_t * obj, const char * value);

//get Key
const char * kvpair_getKey(const kvpair_t * obj);
//get Value
const char * kvpair_getValue(const kvpair_t * obj);

size_t static_kvpair_size();

#endif
