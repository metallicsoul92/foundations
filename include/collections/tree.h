#ifndef FOUNDATIONS_CORE_TREE_H_
#define FOUNDATIONS_CORE_TREE_H_



#ifndef STDDEF_DEFINED
#include <stddef.h>
#define STDDEF_DEFINED 1
#endif

#ifndef TREENODE_DEFINED
typedef struct tree_node treenode_t;
#define TREENODE_DEFINED 1
#endif

/*
TODO: Figure out if i can actually abstract this out? Probably not, right?
*/

//allocation
treenode_t * treenode_malloc(size_t size,size_t depth);
treenode_t * treenode_mallocAndInit(size_t size, size_t depth, void * element);
//free
void treenode_free(treenode_t * self);

//getters
size_t treenode_getSize(treenode_t * self);
size_t treenode_getDepth(treenode_t * self);
void * treenode_getElement(treenode_t * self);
treenode_t * treenode_getParent(treenode_t * self);
treenode_t * treenode_getLeft(treenode_t * self);
treenode_t * treenode_getRight(treenode_t * self);

//setters
void treenode_setSize(treenode_t * self , size_t size);
void treenode_setDepth(treenode_t * self, size_t depth);
void treenode_setElement(treenode_t * self, void * element);
void treenode_setParent(treenode_t * self, treenode_t * parent);
void treenode_setLeft(treenode_t * self, treenode_t * left);
void treenode_setRight(treenode_t * self, treenode_t * right);


#ifndef TREE_DEFINED
typedef struct tree tree_t;
#define TREE_DEFINED 1
#endif


//allocation
tree_t * tree_malloc(size_t size);
//free
void tree_free(tree_t * self);
//properties
size_t tree_getCount(tree_t * self);
size_t tree_getMaxDepth(tree_t * self);
treenode_t * tree_getRootNode(tree_t * self);

void tree_setCount(tree_t * self,size_t count);
void tree_setRootElement(tree_t *self, void * element);


#endif
