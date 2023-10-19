/**
 * @file dlist.h
 * @brief A custom dynamic list (doubly-linked list) library for C.
 *
 * This library provides a basic implementation of a doubly-linked list (dlist)
 * data structure for C. It supports various operations for manipulating the list
 * including appending, prepending, removing elements, inserting elements, and more.
 *
 * @author Clim Jark
 * @version 1.0
 */

#ifndef FOUNDATIONS_CORE_DLIST_H_
#define FOUNDATIONS_CORE_DLIST_H_ 1

// Include necessary standard headers and forward declarations.

#ifndef STDDEF_DEFINED
#include <stddef.h>
#define STDDEF_DEFINED 1
#endif

/** @def DLIST_DEFINED
 *  A macro flag indicating that the `dlist` structure is defined.
 */
#ifndef DLIST_DEFINED
typedef struct dlist dlist_t;
#define DLIST_DEFINED 1
#endif

/**
 * @brief Allocates and initializes a dynamic list with an initial element.
 *
 * @param size    Size of the initial element.
 * @param element Pointer to the initial element's data.
 * @return A pointer to the newly created dlist on success, NULL on memory allocation failure.
 */
dlist_t * dlist_malloc(size_t size, void * element);

/**
 * @brief Frees a dynamic list and its associated elements.
 *
 * @param self Pointer to the dynamic list to be freed.
 */
void dlist_free(dlist_t * self);

/**
 * @brief Appends an element to the end of the dynamic list.
 *
 * @param self    Pointer to the dynamic list.
 * @param element Pointer to the data of the element to be appended.
 */
void dlist_append(dlist_t * self, void * element);

/**
 * @brief Prepends an element to the beginning of the dynamic list.
 *
 * @param self    Pointer to the dynamic list.
 * @param element Pointer to the data of the element to be prepended.
 */
void dlist_prepend(dlist_t * self, void * element);

/**
 * @brief Removes the first element from the dynamic list.
 *
 * @param self Pointer to the dynamic list.
 */
void dlist_removeHead(dlist_t * self);

/**
 * @brief Removes the last element from the dynamic list.
 *
 * @param self Pointer to the dynamic list.
 */
void dlist_removeTail(dlist_t * self);

/**
 * @brief Pops and returns the last element from the dynamic list.
 *
 * @param self Pointer to the dynamic list.
 * @return Pointer to the data of the last element on success, NULL if the list is empty.
 */
void * dlist_popTail(dlist_t * self);

/**
 * @brief Pops and returns the first element from the dynamic list.
 *
 * @param self Pointer to the dynamic list.
 * @return Pointer to the data of the first element on success, NULL if the list is empty.
 */
void * dlist_popHead(dlist_t * self);

/**
 * @brief Pops and returns an element from the dynamic list at the specified index.
 *
 * @param self  Pointer to the dynamic list.
 * @param index Index of the element to pop.
 * @return Pointer to the data of the popped element on success, NULL if the index is out of bounds.
 */
void * dlist_popFrom(dlist_t * self, size_t index);

/**
 * @brief Inserts an element at the specified index within the dynamic list.
 *
 * @param self    Pointer to the dynamic list.
 * @param index   Index at which to insert the element.
 * @param element Pointer to the data of the element to be inserted.
 */
void dlist_insert(dlist_t * self, size_t index, void * element);

/**
 * @brief Removes an element from the dynamic list at the specified index.
 *
 * @param self  Pointer to the dynamic list.
 * @param index Index of the element to be removed.
 */
void dlist_remove(dlist_t * self, size_t index);

/**
 * @brief Retrieves the number of elements in the dynamic list.
 *
 * @param self Pointer to the dynamic list.
 * @return Number of elements in the list.
 */
size_t dlist_getCount(dlist_t * self);

/**
 * @brief Retrieves the data of the last element in the dynamic list.
 *
 * @param self Pointer to the dynamic list.
 * @return Pointer to the data of the last element on success, NULL if the list is empty.
 */
void * dlist_getTailElement(dlist_t * self);

/**
 * @brief Retrieves the data of the first element in the dynamic list.
 *
 * @param self Pointer to the dynamic list.
 * @return Pointer to the data of the first element on success, NULL if the list is empty.
 */
void * dlist_getHeadElement(dlist_t * self);

/**
 * @brief Retrieves the size of the dynamic list.
 *
 * @param self Pointer to the dynamic list.
 * @return Size of the list in bytes.
 */
size_t dlist_getSize(dlist_t * self);

/**
 * @brief Retrieves the data of an element in the dynamic list at the specified index.
 *
 * @param self  Pointer to the dynamic list.
 * @param count Index of the element to retrieve.
 * @return Pointer to the data of the element at the specified index on success, NULL if the index is out of bounds.
 */
void * dlist_getElementByIndex(dlist_t * self, size_t count);

#endif
