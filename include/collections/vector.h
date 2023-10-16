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

//No Errors
#define VEC_FLAG_NONE 0
//Set when vector_pop is used on an empty vector
#define VEC_FLAG_EMPTY 1
//Set when vector_push is used on a full vector
#define VEC_FLAG_FULL 2
//Set when resizing to a lower capacity with elements in the way
#define VEC_FLAG_INVALID_RESIZE 3



typedef struct vector vector_t;

//properties
size_t vector_getSize(vector_t * out);
size_t vector_getCapacity(vector_t * out);
size_t vector_getCount(vector_t * out);
uint8_t vector_eFlag(vector_t * out);
void * vector_getElementAt(vector_t * out, size_t index);
//literally returns the starting address? I dont know i need to
//figure out whether i need to deprecate this or not .
void * vector_getRawData(vector_t * out);

//Memory Allocation
vector_t * vector_malloc(size_t size, size_t capacity);
//Genuinely dont understand a usecase for this one....
vector_t * vector_init(vector_t * out, size_t size, size_t capacity);

//other allocations
vector_t * vector_copy(const vector_t * copy);
vector_t * vector_move(vector_t * move);

//free
void free_vector(vector_t * out);

//
void vector_empty(vector_t * out);

//Vector Operations
void vector_push(vector_t *out, void * element);
void * vector_pop(vector_t * out);

//Safe way of resizing
void vector_resize(vector_t * out);

//Unsafe way of resizing
void vector_exactResize(vector_t * out, size_t newCap);


#endif
