/**
 * @file slist.h
 * @brief A custom singly-linked list library for C.
 *
 * This library provides a basic implementation of a singly-linked list data structure for C. A singly-linked list is a linear data structure in which elements are connected sequentially, and each element points to the next one. This library allows you to create, manipulate, and free singly-linked lists. It provides functions to create, append, prepend, remove, pop elements, and get information about the list.
 *
 * @author Clim Jark
 * @version 1.0
 */

#ifndef FOUNDATIONS_CORE_SLIST_H_
#define FOUNDATIONS_CORE_SLIST_H_

// Include necessary standard headers and forward declarations.

#ifndef STDDEF_DEFINED
#include <stddef.h>
#define STDDEF_DEFINED 1
#endif

/**
 * @typedef slist_t
 * Opaque pointer to the singly-linked list structure (hides the implementation details).
 */
typedef struct slist slist_t;

/**
 * @brief Creates a new singly-linked list with an optional initial element.
 *
 * @param size The size of the initial element.
 * @param element The initial element (can be NULL for an empty list).
 * @return A pointer to the newly created singly-linked list on success, or NULL on memory allocation failure.
 */
slist_t * slist_malloc(size_t size, void * element);

/**
 * @brief Creates a new empty singly-linked list.
 *
 * @return A pointer to the newly created empty singly-linked list on success, or NULL on memory allocation failure.
 */
slist_t * slist_mallocEmpty();

/**
 * @brief Frees the memory used by the singly-linked list.
 *
 * @param self The singly-linked list to be freed.
 */
void slist_free(slist_t * self);

/**
 * @brief Appends an element to the end of the singly-linked list.
 *
 * @param self The singly-linked list to append to.
 * @param element The element to append.
 * @param size The size of the element.
 */
void slist_append(slist_t * self, void * element, size_t size);

/**
 * @brief Prepends an element to the beginning of the singly-linked list.
 *
 * @param self The singly-linked list to prepend to.
 * @param element The element to prepend.
 * @param size The size of the element.
 */
void slist_prepend(slist_t * self, void * element, size_t size);

/**
 * @brief Removes the head element from the singly-linked list.
 *
 * @param self The singly-linked list to remove from.
 */
void slist_removeHead(slist_t *self);

/**
 * @brief Removes the tail element from the singly-linked list.
 *
 * @param self The singly-linked list to remove from.
 */
void slist_removeTail(slist_t * self);

/**
 * @brief Pops and retrieves the tail element from the singly-linked list.
 *
 * @param self The singly-linked list to pop from.
 * @return The popped element on success, or NULL if the list is empty.
 */
void * slist_popTail(slist_t * self);

/**
 * @brief Pops and retrieves the head element from the singly-linked list.
 *
 * @param self The singly-linked list to pop from.
 * @return The popped element on success, or NULL if the list is empty.
 */
void * slist_popHead(slist_t * self);

/**
 * @brief Pops and retrieves an element from the specified index in the singly-linked list.
 *
 * @param self The singly-linked list to pop from.
 * @param index The index of the element to pop.
 * @return The popped element on success, or NULL if the index is out of bounds.
 */
void * slist_popFrom(slist_t * self, size_t index);

/**
 * @brief Inserts an element at the specified index in the singly-linked list.
 *
 * @param self The singly-linked list to insert into.
 * @param index The index at which to insert the element.
 * @param element The element to insert.
 * @param size The size of the element.
 */
void slist_insert(slist_t * self, size_t index, void * element, size_t size);

/**
 * @brief Removes an element from the specified index in the singly-linked list.
 *
 * @param self The singly-linked list to remove from.
 * @param index The index of the element to remove.
 */
void slist_remove(slist_t * self, size_t index);

/**
 * @brief Gets the number of elements in the singly-linked list.
 *
 * @param self The singly-linked list to query.
 * @return The number of elements in the list.
 */
size_t slist_getCount(slist_t * self);

/**
 * @brief Gets the tail element of the singly-linked list.
 *
 * @param self The singly-linked list to query.
 * @return The tail element on success, or NULL if the list is empty.
 */
void * slist_getTailElement(slist_t * self);

/**
 * @brief Gets the head element of the singly-linked list.
 *
 * @param self The singly-linked list to query.
 * @return The head element on success, or NULL if the list is empty.
 */
void * slist_getHeadElement(slist_t * self);

/**
 * @brief Gets the size of the singly-linked list.
 *
 * @param self The singly-linked list to query.
 * @return The total size of the list.
 */
size_t slist_getSize(slist_t * self);

/**
 * @brief Gets an element from the singly-linked list at the specified index.
 *
 * @param self The singly-linked list to query.
 * @param count The index of the element to retrieve.
 * @return The element at the specified index on success, or NULL if the index is out of bounds.
 */
void * slist_getElementByIndex(slist_t * self, size_t count);

#endif
