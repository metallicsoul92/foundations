#include "../../include/collections/tree.h"

#include <stdlib.h>
#include <string.h>



struct tree_node{
  size_t _size;
  size_t _depth;
  void * _element;
  treenode_t *_parent;
  treenode_t *_left;
  treenode_t *_right;
};

//allocation
treenode_t * treenode_malloc(size_t size, size_t depth){
  treenode_t * out = malloc(sizeof(treenode_t));
  out->_size = size;
  out->_depth = depth;
  out->_element = NULL;
  out->_parent = NULL;
  out->_left = NULL;
  out->_right = NULL;
  return out;
}
treenode_t * treenode_mallocAndInit(size_t size, size_t depth, void * element){
  treenode_t * out = malloc(sizeof(treenode_t));
  out->_size = size;
  out->_depth = depth;
  treenode_setElement(out,element);
  out->_parent = NULL;
  out->_left = NULL;
  out->_right = NULL;
  return out;
}

//TODO: FIX THIS

void treenode_free(treenode_t * self){
  if(self->_element != NULL){
    free(self->_element);
  }
  if(self->_left != NULL){
    treenode_free(self->_left);
  }
  if(self->_right != NULL){
    treenode_free(self->_right);
  }
  free(self);
}

//getters
size_t treenode_getSize(treenode_t * self){
  return self->_size;
}
size_t treenode_getDepth(treenode_t * self){
  return self->_depth;
}
void * treenode_getElement(treenode_t * self){
  return self->_element;
}
treenode_t * treenode_getParent(treenode_t * self){
  return self->_parent;
}
treenode_t * treenode_getLeft(treenode_t * self){
  return self->_left;
}
treenode_t * treenode_getRight(treenode_t * self){
  return self->_right;
}

//setters
void treenode_setSize(treenode_t * self , size_t size){
  self->_size = size;
}
void treenode_setDepth(treenode_t * self, size_t depth){
  self->_depth = depth;
}
void treenode_setElement(treenode_t * self, void * element){
  self->_element =  malloc(self->_size);
  memcpy(self->_element,element,self->_size);
}
void treenode_setParent(treenode_t * self, treenode_t * parent){
  self->_parent = parent;

}
void treenode_setLeft(treenode_t * self, treenode_t * left){
  self->_left = left;
}
void treenode_setRight(treenode_t * self, treenode_t * right){
  self->_right = right;
}


struct tree{
  size_t _count;
  size_t _maxDepth;
  treenode_t *_internal;
  treenode_t *_iter;
};

//allocation
tree_t * tree_malloc(size_t size){
  tree_t * out = malloc(sizeof(tree_t));
  out->_count = 0;
  out->_maxDepth = 0;
  out->_internal = treenode_malloc(size,1);
  out->_iter = out->_internal;
  return out;
}
//free
void tree_free(tree_t * self){
  treenode_free(self->_internal);
  self->_iter = NULL;
  free(self);
}
//properties
size_t tree_getCount(tree_t * self){
  return self->_count;
}
size_t tree_getMaxDepth(tree_t * self){
  return self->_maxDepth;
}
treenode_t * tree_getRootNode(tree_t * self){
  return self->_internal;
}
treenode_t * tree_iterator(tree_t * self){
  return self->_iter;
}

void tree_setCount(tree_t * self, size_t count){
  self->_count = count;
}
void tree_setRootElement(tree_t *self, void * element){
  treenode_setElement(self->_internal,element);
}
