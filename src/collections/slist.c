#include "../../include/collections/slist.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/*
Private API

*/
#ifndef SLISTNODE_DEFINED
typedef struct slist_node slistnode_t;
#define SLISTNODE_DEFINED 1
#endif

struct slist_node{
  void *_element;
  size_t _size;
  slistnode_t * _next;
};

/**
  Forward Declare
**/
//construction/destruction
slistnode_t * slistnode_malloc(void * element,size_t size);
slistnode_t * slistnode_mallocAndAttach(void * element, size_t size, slistnode_t * other);
void slistnode_free(slistnode_t * self);
void slistnode_freeAll(slistnode_t *self);

//setters
void slistnode_setElement(slistnode_t * self, void * element);
void slistnode_setNext(slistnode_t * self, slistnode_t * next);

//properties
void * slistnode_getElemement(slistnode_t * self);
slistnode_t * slistnode_getNext(slistnode_t * self);
size_t slistnode_getSize(slistnode_t * self);
slistnode_t * slistnode_getTail(slistnode_t *self);




//construction/destruction
slistnode_t * slistnode_malloc(void * element, size_t size) {
  slistnode_t * out = malloc(sizeof(slistnode_t));

  if (out == NULL) {
    // Handle memory allocation failure, if needed.
    return NULL;
  }

  out->_element = malloc(size);

  if (out->_element == NULL) {
    // Handle memory allocation failure, if needed.
    free(out);
    return NULL;
  }

  memcpy(out->_element, element, size);
  out->_size = size;
  out->_next = NULL;

  return out;
}
//returns the newly allocated node. This will Attach the new node
//to the other node.
slistnode_t * slistnode_mallocAndAttach(void * element, size_t size, slistnode_t * other){
  slistnode_t * out = malloc(sizeof(slistnode_t));
  out->_element = element;
  out->_size = size;
  out->_next = NULL;
  slistnode_setNext(other,out);

  return out;
}

void slistnode_free(slistnode_t * self){
  self->_size = 0;
  if(self->_element != NULL){
	free(self->_element);
	}else
  	printf("SLIST_ERROR : element unreachable?\n");
}

void slistnode_freeAll(slistnode_t *self) {
  slistnode_t *current = self;

  while (current != NULL) {
    slistnode_t *tmp = current;
    current = current->_next;
    slistnode_free(tmp);
    free(tmp);
  }
}

//setters
void slistnode_setElement(slistnode_t * self, void * element){
  memcpy(self->_element, element,self->_size);

}
void slistnode_setNext(slistnode_t * self, slistnode_t * next){
  memcpy(self->_next, next,next->_size);
}

//properties
void * slistnode_getElemement(slistnode_t * self){
  return self->_element;
}
slistnode_t * slistnode_getNext(slistnode_t * self){
  return self->_next;
}
size_t slistnode_getSize(slistnode_t * self){
  return self->_size;
}

slistnode_t * slistnode_getTail(slistnode_t *self){
  while(self->_next != NULL){
    self = self->_next;
  }
  return self;
}


struct slist{
  size_t _count;
  slistnode_t *_head;
  slistnode_t *_tail;
};


slist_t * slist_malloc(size_t size, void * element){
  slist_t * out = malloc(sizeof(slist_t));
  out->_head = slistnode_malloc(element, size);
  out->_tail = out->_head;
  out->_count = 1;
  return out;
}

slist_t * slist_mallocEmpty(){
  slist_t * out = malloc(sizeof(slist_t));
  out->_head = NULL;
  out->_tail = out->_head;
  out->_count = 0;
  return out;
}

void slist_free(slist_t * self){
  slistnode_freeAll(self->_head);
  free(self);
}

void slist_append(slist_t * self,void * element,size_t size){
  slistnode_t * node = slistnode_malloc(element,size);
  if( self->_count == 0){
  self->_head = node;
  self->_tail = node;
 }if(self->_count >= 1){
  self->_tail->_next = node;
  self->_tail = node;
  }
  self->_count++;
}

void slist_prepend(slist_t *self, void *element, size_t size) {
  if (self == NULL) {
    // Handle the case where the list is invalid (NULL).
    return;
  }

  // Create a new node with the specified element and size.
  slistnode_t *node = slistnode_malloc(element, size);

  if (node == NULL) {
    // Handle memory allocation failure, if needed.
    return;
  }

  if (self->_count == 0) {
    // If the list is empty, both head and tail should be updated.
    self->_head = node;
    self->_tail = node;
  } else {
    slistnode_t *currHead = self->_head;
    node->_next = currHead;
    self->_head = node;
  }

  // Increase the count to reflect the added node.
  self->_count++;
}

void slist_removeHead(slist_t *self){
  if(self->_head->_next == NULL){
    slistnode_free(self->_head);
    return;
  }
  slistnode_t * currHead = self->_head;
  slistnode_t * nextHead = self->_head->_next;
  slistnode_free(currHead);
  self->_head = nextHead;
  self->_count--;
}
void slist_removeTail(slist_t * self){
  //figure out the tail situation
  slistnode_t * tail = self->_tail;
  //setup an iterator to get one before the tail
  slistnode_t * iter = self->_head;
  while(iter->_next != tail){
    iter = slistnode_getNext(iter);
  }
  iter->_next = NULL;
  slistnode_free(tail);
  self->_count--;
}

void * slist_popHead(slist_t * self){
  slistnode_t * currHead = self->_head;
  slistnode_t * nextHead = self->_head->_next;

  void * mem = malloc(sizeof(self->_head->_size));
  memcpy(mem, self->_head->_element, self->_head->_size);
  slistnode_free(currHead);
  self->_head = nextHead;
  self->_count--;
  return mem;
}


void * slist_popTail(slist_t * self){
  //figure out the tail situation
  slistnode_t * tail = self->_tail;
  //setup an iterator to get one before the tail
  slistnode_t * iter = self->_head;
  while(iter->_next != tail){
    iter = slistnode_getNext(iter);
  }
  //now that we are at the tail, set the pointer to null
  iter->_next = NULL;
  //allocate memory to send back from the pop , and set it to the contents of the
  // iterator
  void * mem = malloc(self->_head->_size);
  memcpy(mem,iter->_element,self->_head->_size);
  //free the tail
  slistnode_free(tail);
  //set the list's tail pointer to the iterator
  self->_tail = iter;
  self->_count--;
  return mem;
}

void * slist_popFrom(slist_t * self,size_t index){
  if(index > self->_count){
    return NULL;
  }
  slistnode_t * iter = self->_head;
    for(size_t i = 0; i < index; i++){
      iter = iter->_next;
    }
    void * mem = malloc(self->_head->_size);
    memcpy(mem,iter->_element,self->_head->_size);
    slist_remove(self,index);
    self->_count--;
    return mem;
}


void slist_insert(slist_t *self, size_t index, void *element, size_t size) {
  if (self == NULL) {
    // Handle the case where the list is invalid (NULL).
    return;
  }

  if (index > self->_count) {
    // Handle the case where the index is out of bounds.
    return;
  }

  // Create a new node with the specified element and size.
  slistnode_t *newNode = slistnode_malloc(element, size);

  if (newNode == NULL) {
    // Handle memory allocation failure, if needed.
    return;
  }

  if (index == 0) {
    // Inserting at the beginning.
    newNode->_next = self->_head;
    self->_head = newNode;

    if (self->_tail == NULL) {
      // If this is the first node in an empty list, update the tail.
      self->_tail = newNode;
    }
  } else {
    size_t i = 0;
    slistnode_t *iter = self->_head;

    // Traverse the list to the node before the specified index.
    while (i < index - 1) {
      iter = iter->_next;
      i++;

      if (iter == NULL) {
        // Handle the case where the list is not properly initialized or index is invalid.
        slistnode_free(newNode);
        return;
      }
    }

    // Insert the new node.
    newNode->_next = iter->_next;
    iter->_next = newNode;

    if (newNode->_next == NULL) {
      // If we inserted at the end, update the tail.
      self->_tail = newNode;
    }
  }

  // Increase the count to reflect the added node.
  self->_count++;
}


void slist_remove(slist_t *self, size_t index) {
  if (self == NULL || index >= self->_count) {
    // Handle the case where the list is invalid (NULL) or the index is out of bounds.
    return;
  }

  if (index == 0) {
    // Removing the first node.
    slistnode_t *nodeToRemove = self->_head;
    self->_head = self->_head->_next;

    // Free the memory associated with the removed node.
    slistnode_free(nodeToRemove);
  } else {
    size_t i = 0;
    slistnode_t *iter = self->_head;

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
      slistnode_t *nodeToRemove = iter->_next;
      iter->_next = nodeToRemove->_next;

      // Free the memory associated with the removed node.
      slistnode_free(nodeToRemove);
    }
  }

  // Decrease the count to reflect the removed node.
  self->_count--;
}

size_t slist_getCount(slist_t * self){
  return self->_count;
}
void * slist_getTailElement(slist_t * self){
  return self->_tail->_element;
}
void * slist_getHeadElement(slist_t * self){
  return self->_head->_element;
}
size_t slist_getSize(slist_t * self){
  return slistnode_getSize(self->_head);
}

void * slist_getElementByIndex(slist_t * self, size_t count){
  if(count > self->_count){
    return NULL;
  }
  slistnode_t * iter = self->_head;
    for(size_t i = 0; i < count; i++){
      iter = iter->_next;
    }
    return iter->_element;
}
