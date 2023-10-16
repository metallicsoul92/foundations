#ifndef FOUNDATIONS_CORE_DLIST_H_
#define FOUNDATIONS_CORE_DLIST_H_ 1



#ifndef STDDEF_DEFINED
#include <stddef.h>
#define STDDEF_DEFINED 1
#endif

#ifndef DLIST_DEFINED
typedef struct dlist dlist_t;
#define DLIST_DEFINED 1
#endif


dlist_t * dlist_malloc(size_t size, void * element);

void dlist_free(dlist_t * self);

void dlist_append(dlist_t * self, void * element);
void dlist_prepend(dlist_t * self, void * element);
void dlist_removeHead(dlist_t *self);
void dlist_removeTail(dlist_t * self);
void * dlist_popTail(dlist_t * self);
void * dlist_popHead(dlist_t * self);
void * dlist_popFrom(dlist_t * self,size_t index);
void dlist_insert(dlist_t * self, size_t index, void * element);
void dlist_remove(dlist_t * self, size_t index);

size_t dlist_getCount(dlist_t * self);
void * dlist_getTailElement(dlist_t * self);
void * dlist_getHeadElement(dlist_t * self);
size_t dlist_getSize(dlist_t * self);

void * dlist_getElementByIndex(dlist_t * self, size_t count);


#endif
