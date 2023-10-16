#ifndef FOUNDATIONS_CORE_SLIST_H_
#define FOUNDATIONS_CORE_SLIST_H_



#ifndef STDDEF_DEFINED
#include <stddef.h>
#define STDDEF_DEFINED 1
#endif

#ifndef SLIST_DEFINED
typedef struct slist slist_t;
#define SLIST_DEFINED 1
#endif


slist_t * slist_malloc(size_t size, void * element);
slist_t * slist_mallocEmpty();

void slist_free(slist_t * self);

void slist_append(slist_t * self, void * element, size_t size);
void slist_prepend(slist_t * self, void * element, size_t size);
void slist_removeHead(slist_t *self);
void slist_removeTail(slist_t * self);
void * slist_popTail(slist_t * self);
void * slist_popHead(slist_t * self);
void * slist_popFrom(slist_t * self,size_t index);
void slist_insert(slist_t * self, size_t index, void * element,size_t size);
void slist_remove(slist_t * self, size_t index);

size_t slist_getCount(slist_t * self);
void * slist_getTailElement(slist_t * self);
void * slist_getHeadElement(slist_t * self);
size_t slist_getSize(slist_t * self);

void * slist_getElementByIndex(slist_t * self, size_t count);


#endif
