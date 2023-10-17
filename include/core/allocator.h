#ifndef FOUNDATIONS_CORE_ALLOCATOR_H_
#define FOUNDATIONS_CORE_ALLOCATOR_H_

//Allocator Wants:
//1. Initial size customization upon creation
//2. Thread safe? or atleast lockable and such?
//3. Basic malloc and free implemented
//   a. Can probably end up returning offsets within
//      previously allocated memory with memory guards
//   b. freeing can consist of memsetting to 0 , with
//	    the size of the element ?

#ifndef STDINT_DEFINED
	#include <stdint.h>
	#define STDINT_DEFINED 1
#endif

#ifndef STDDEF_DEFINED
#include <stddef.h>
#define STDDEF_DEFINED 1
#endif

#define ALLOC_SUCCESS 0
#define ALLOC_NOMEM   1
#define ALLOC_BINFAIL 16


#ifndef ALLOCATOR_DEFINED
	typedef struct  _allocator allocator_t;
	#define ALLOCATOR_DEFINED 1
#endif

//Initializing the allocator
uint8_t allocator_init(allocator_t * allocator);
uint8_t static_allocator_init();

//destroying the allocator
void allocator_destroy(allocator_t * self);


//STATIC API
//	set the current allocator
//	used when not specifying which allocator to use when
//	allocing or freeing memory?
void static_set_allocator(allocator_t * alloc);

//allocation from the current alllocator that is initialized
void * static_allocator_malloc(size_t size);
void * static_allocator_calloc(size_t size);
void * static_allocator_realloc(void * address, size_t size);

//allocation from the specified allocator.
void * allocator_malloc(allocator_t * allocator, size_t size);
void * allocator_calloc(allocator_t * allocator, size_t size);
void * allocator_realloc(allocator_t * allocator,void * address, size_t size);
//freeing memory within the allocator
void static_allocator_free(void * address);
void allocator_free(allocator_t * self, void * address);

#endif
