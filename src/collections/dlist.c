#include "../../include/collections/dlist.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/*
Private API

*/
#ifndef DLISTNODE_DEFINED
typedef struct dlist_node dlistnode_t;
#define DLISTNODE_DEFINED 1
#endif

struct dlist_node{
  void *_element;
  size_t _size;
  dlistnode_t * _prev;
  dlistnode_t * _next;
};


/**
  Forward Declare
**/
//construction/destruction
dlistnode_t * dlistnode_malloc(void * element,size_t size);
dlistnode_t * dlistnode_mallocAndAttach(void * element, size_t size, dlistnode_t * other);
void dlistnode_free(dlistnode_t * self);
void dlistnode_freeAll(dlistnode_t *self);

//setters
void dlistnode_setElement(dlistnode_t * self, void * element);
void dlistnode_setNext(dlistnode_t * self, dlistnode_t * next);
void dlistnode_setPrevious(dlistnode_t * self, dlistnode_t * prev);

//properties
void * dlistnode_getElemement(dlistnode_t * self);
dlistnode_t * dlistnode_getPrevious(dlistnode_t * self);
dlistnode_t * dlistnode_getNext(dlistnode_t * self);
size_t dlistnode_getSize(dlistnode_t * self);
dlistnode_t * dlistnode_getTail(dlistnode_t *self);




//construction/destruction
dlistnode_t * dlistnode_malloc(void * element,size_t size){
  dlistnode_t * out = malloc(sizeof(dlistnode_t));
  out->_element = element;
  out->_size = size;
  out->_next = NULL;
  out->_prev = NULL;
  return out;
}
//returns the newly allocated node. This will Attach the new node
//to the other node.
dlistnode_t * dlistnode_mallocAndAttach(void * element, size_t size, dlistnode_t * other){
  dlistnode_t * out = malloc(sizeof(dlistnode_t));
  out->_element = element;
  out->_size = size;
  out->_next = NULL;
  dlistnode_setNext(other,out);

  return out;
}

void dlistnode_free(dlistnode_t * self){
  self->_size = 0;
  free(self->_element);
  free(self);
}
void dlistnode_freeAll(dlistnode_t *self){
  dlistnode_t * iter = self;
  while(self->_next != NULL){
    while(iter->_next != NULL){
      iter = iter->_next;
   }
    dlistnode_free(iter);
    iter = self;
  }
}

//setters
void dlistnode_setElement(dlistnode_t * self, void * element){
  self->_element = element;
}
void dlistnode_setNext(dlistnode_t * self, dlistnode_t * next){
  self->_next = next;
  next->_prev = self;
}
void dlistnode_setPrevious(dlistnode_t * self, dlistnode_t * prev){
  self->_prev = prev;
  prev->_next = self;
}
//properties
void * dlistnode_getElemement(dlistnode_t * self){
  return self->_element;
}
dlistnode_t * dlistnode_getPrevious(dlistnode_t * self){
  return self->_prev;
}
dlistnode_t * dlistnode_getNext(dlistnode_t * self){
  return self->_next;
}
size_t dlistnode_getSize(dlistnode_t * self){
  return self->_size;
}

dlistnode_t * dlistnode_getTail(dlistnode_t *self){
  while(self->_next != NULL){
    self = self->_next;
  }
  return self;
}


struct dlist{
  size_t _count;
  dlistnode_t *_head;
  dlistnode_t *_tail;
};


dlist_t * dlist_malloc(size_t size, void * element){
  dlist_t * out = malloc(sizeof(dlist_t));
  out->_head = dlistnode_malloc(element, size);
  out->_tail = out->_head;
  out->_count = 1;
  return out;
}

void dlist_free(dlist_t * self){
  dlistnode_freeAll(self->_head);
  free(self);
}

void dlist_append(dlist_t *self, void *element) {
    dlistnode_t *node = dlistnode_mallocAndAttach(element, sizeof(*element), self->_tail);
    if (self->_tail == NULL) {
        // The list was initially empty; set both head and tail to the new node.
        self->_head = node;
        self->_tail = node;
    } else {
        // Update the tail to the new node.
        self->_tail = node;
    }
    self->_count++;
}
void dlist_prepend(dlist_t * self, void * element){
  dlistnode_t * node = dlistnode_malloc(element,self->_head->_size);
  dlistnode_t * currHead = self->_head;
  currHead->_prev = node;
  node->_next = currHead;
  self->_head = node;
  self->_count++;
}

void dlist_removeHead(dlist_t *self){
  if(self->_head->_next == NULL){
    dlistnode_free(self->_head);
    return;
  }
  dlistnode_t * currHead = self->_head;
  dlistnode_t * nextHead = self->_head->_next;
  free(currHead);
  self->_head = nextHead;
  self->_count--;
}
void dlist_removeTail(dlist_t * self) {
  if (self->_tail == NULL) {
    // Handle the case where the list is empty.
    return;
  }

  dlistnode_t * tail = self->_tail;
  dlistnode_t * prevNode = tail->_prev;

  if (prevNode == NULL) {
    // Handle the case where the tail is also the head (no previous node).
    // You can choose to return an error code or use another approach as needed.
    // In this example, I'll update the head to NULL to indicate an empty list.
    self->_head = NULL;
  } else {
    // Update the tail.
    self->_tail = prevNode;
    // Make sure the previous node's "next" pointer is set to NULL.
    prevNode->_next = NULL;
  }

  // Free the memory associated with the removed tail node.
  dlistnode_free(tail);

  // Decrease the count.
  self->_count--;
}

void *dlist_popHead(dlist_t *self) {
  if (self == NULL || self->_head == NULL) {
    // Handle the case where the list is empty or invalid.
    return NULL;
  }

  dlistnode_t *currHead = self->_head;
  dlistnode_t *nextHead = self->_head->_next;

  // Get the size of the element.
  size_t elementSize = currHead->_size;

  // Allocate memory for the element and copy it.
  void *mem = malloc(elementSize);
  if (mem == NULL) {
    // Handle memory allocation failure, if needed.
    return NULL;
  }
  memcpy(mem, currHead->_element, elementSize);

  // Update the head and count.
  self->_head = nextHead;
  self->_count--;

  // Free the memory associated with the removed node.
  dlistnode_free(currHead);

  return mem;
}


void *dlist_popTail(dlist_t *self) {
  if (self == NULL || self->_tail == NULL) {
    // Handle the case where the list is empty or invalid.
    return NULL;
  }

  dlistnode_t *tail = self->_tail;
  dlistnode_t *prevNode = tail->_prev;

  if (prevNode == NULL) {
    // Handle the case where the tail is also the head (no previous node).
    // You can choose to return an error code or use another approach as needed.
    return NULL;
  }

  // Get the size of the element.
  size_t elementSize = tail->_size;

  // Allocate memory for the element and copy it.
  void *mem = malloc(elementSize);
  if (mem == NULL) {
    // Handle memory allocation failure, if needed.
    return NULL;
  }
  memcpy(mem, prevNode->_element, elementSize);

  // Update the tail and count.
  self->_tail = prevNode;
  self->_count--;

  // Free the memory associated with the removed tail node.
  dlistnode_free(tail);

  return mem;
}

void * dlist_popFrom(dlist_t * self,size_t index){
  if(index > self->_count){
    return NULL;
  }
  dlistnode_t * iter = self->_head;
    for(size_t i = 0; i < index; i++){
      iter = iter->_next;
    }
    void * mem = malloc(self->_head->_size);
    memcpy(mem,iter->_element,self->_head->_size);
    dlist_remove(self,index);
    self->_count--;
    return mem;
}


void dlist_insert(dlist_t * self, size_t index, void * element) {
  if (self == NULL) {
    // Handle the case where the list is invalid (NULL).
    return;
  }

  if (index > self->_count) {
    // Handle the case where the index is out of bounds.
    return;
  }

  // Create a new node with the specified element.
  dlistnode_t * newNode = dlistnode_malloc(element, self->_head->_size);

  if (newNode == NULL) {
    // Handle memory allocation failure, if needed.
    return;
  }

  if (index == 0) {
    // Inserting at the beginning.
    newNode->_next = self->_head;
    self->_head = newNode;
  } else {
    size_t i = 0;
    dlistnode_t * iter = self->_head;

    // Traverse the list to the node before the specified index.
    while (i < index - 1) {
      iter = iter->_next;
      i++;

      if (iter == NULL) {
        // Handle the case where the list is not properly initialized or index is invalid.
        dlistnode_free(newNode);
        return;
      }
    }

    // Insert the new node.
    newNode->_next = iter->_next;
    iter->_next = newNode;
  }

  // Increase the count to reflect the added node.
  self->_count++;
}

void dlist_remove(dlist_t * self, size_t index) {
  if (self == NULL || index >= self->_count) {
    // Handle the case where the list is invalid (NULL) or the index is out of bounds.
    return;
  }

  if (index == 0) {
    // Removing the first node.
    dlistnode_t *nodeToRemove = self->_head;
    self->_head = self->_head->_next;

    if (self->_head != NULL) {
      // Update the new head's previous pointer to NULL.
      self->_head->_prev = NULL;
    }

    // Free the memory associated with the removed node.
    dlistnode_free(nodeToRemove);
  } else {
    size_t i = 0;
    dlistnode_t * iter = self->_head;

    // Traverse the list to the node before the specified index.
    while (i < index - 1) {
      iter = iter->_next;
      i++;

      if (iter == NULL) {
        // Handle the case where the list is not properly initialized or index is invalid.
        return;
      }
    }

    if (iter->_next != NULL) {
      dlistnode_t *nodeToRemove = iter->_next;
      iter->_next = nodeToRemove->_next;

      if (nodeToRemove->_next != NULL) {
        // Update the next node's previous pointer.
        nodeToRemove->_next->_prev = iter;
      }

      // Free the memory associated with the removed node.
      dlistnode_free(nodeToRemove);
    }
  }

  // Decrease the count to reflect the removed node.
  self->_count--;
}


size_t dlist_getCount(dlist_t * self){
  return self->_count;
}
void * dlist_getTailElement(dlist_t * self){
  return self->_tail->_element;
}
void * dlist_getHeadElement(dlist_t * self){
  return self->_head->_element;
}
size_t dlist_getSize(dlist_t * self){
  return dlistnode_getSize(self->_head);
}

void * dlist_getElementByIndex(dlist_t * self, size_t count){
  if(count > self->_count){
    return NULL;
  }
  dlistnode_t * iter = self->_head;
    for(size_t i = 0; i < count; i++){
      iter = iter->_next;
    }
    return iter->_element;
}
