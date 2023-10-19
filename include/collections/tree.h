/**
 * @file tree.h
 * @brief A custom tree library for C.
 *
 * This library provides a basic implementation of a tree data structure for C. A tree is a hierarchical data structure with a root element and child elements, forming a structure with nodes and edges. This library allows you to create, manipulate, and free trees. It provides functions for allocating nodes, setting their properties, and working with tree structures.
 *
 * @author Clim Jark
 * @version 1.0
 */

#ifndef FOUNDATIONS_CORE_TREE_H_
#define FOUNDATIONS_CORE_TREE_H_

/**
 * @typedef treenode_t
 * Opaque pointer to the tree node structure (hides the implementation details).
 */
typedef struct tree_node treenode_t;

#ifndef STDDEF_DEFINED
#include <stddef.h>
#define STDDEF_DEFINED 1
#endif

/**
 * @brief Allocates a new tree node with the specified size and depth.
 *
 * @param size The size of the tree node.
 * @param depth The depth of the tree node.
 * @return A pointer to the newly allocated tree node.
 */
treenode_t *treenode_malloc(size_t size, size_t depth);

/**
 * @brief Allocates a new tree node with the specified size, depth, and initial element.
 *
 * @param size The size of the tree node.
 * @param depth The depth of the tree node.
 * @param element A pointer to the initial element to be stored in the tree node.
 * @return A pointer to the newly allocated tree node.
 */
treenode_t *treenode_mallocAndInit(size_t size, size_t depth, void *element);

/**
 * @brief Frees the memory used by a tree node and its child nodes.
 *
 * @param self The tree node to be freed.
 */
void treenode_free(treenode_t *self);

/**
 * @brief Retrieves the size of a tree node.
 *
 * @param self The tree node.
 * @return The size of the tree node.
 */
size_t treenode_getSize(treenode_t *self);

/**
 * @brief Retrieves the depth of a tree node.
 *
 * @param self The tree node.
 * @return The depth of the tree node.
 */
size_t treenode_getDepth(treenode_t *self);

/**
 * @brief Retrieves the element stored in a tree node.
 *
 * @param self The tree node.
 * @return A pointer to the element stored in the tree node.
 */
void *treenode_getElement(treenode_t *self);

/**
 * @brief Retrieves the parent node of a tree node.
 *
 * @param self The tree node.
 * @return A pointer to the parent node.
 */
treenode_t *treenode_getParent(treenode_t *self);

/**
 * @brief Retrieves the left child node of a tree node.
 *
 * @param self The tree node.
 * @return A pointer to the left child node.
 */
treenode_t *treenode_getLeft(treenode_t *self);

/**
 * @brief Retrieves the right child node of a tree node.
 *
 * @param self The tree node.
 * @return A pointer to the right child node.
 */
treenode_t *treenode_getRight(treenode_t *self);

/**
 * @brief Sets the size of a tree node.
 *
 * @param self The tree node.
 * @param size The new size to set.
 */
void treenode_setSize(treenode_t *self, size_t size);

/**
 * @brief Sets the depth of a tree node.
 *
 * @param self The tree node.
 * @param depth The new depth to set.
 */
void treenode_setDepth(treenode_t *self, size_t depth);

/**
 * @brief Sets the element of a tree node.
 *
 * @param self The tree node.
 * @param element A pointer to the new element to set.
 */
void treenode_setElement(treenode_t *self, void *element);

/**
 * @brief Sets the parent node of a tree node.
 *
 * @param self The tree node.
 * @param parent A pointer to the new parent node.
 */
void treenode_setParent(treenode_t *self, treenode_t *parent);

/**
 * @brief Sets the left child node of a tree node.
 *
 * @param self The tree node.
 * @param left A pointer to the new left child node.
 */
void treenode_setLeft(treenode_t *self, treenode_t *left);

/**
 * @brief Sets the right child node of a tree node.
 *
 * @param self The tree node.
 * @param right A pointer to the new right child node.
 */
void treenode_setRight(treenode_t *self, treenode_t *right);

/**
 * @typedef tree_t
 * Opaque pointer to the tree structure (hides the implementation details).
 */
typedef struct tree tree_t;

/**
 * @brief Allocates a new tree with the specified size.
 *
 * @param size The size of the tree.
 * @return A pointer to the newly allocated tree.
 */
tree_t *tree_malloc(size_t size);

/**
 * @brief Frees the memory used by a tree and all its nodes.
 *
 * @param self The tree to be freed.
 */
void tree_free(tree_t *self);

/**
 * @brief Retrieves the number of nodes in a tree.
 *
 * @param self The tree.
 * @return The count of nodes in the tree.
 */
size_t tree_getCount(tree_t *self);

/**
 * @brief Retrieves the maximum depth of a tree.
 *
 * @param self The tree.
 * @return The maximum depth of the tree.
 */
size_t tree_getMaxDepth(tree_t *self);

/**
 * @brief Retrieves the root node of a tree.
 *
 * @param self The tree.
 * @return A pointer to the root node of the tree.
 */
treenode_t *tree_getRootNode(tree_t *self);

/**
 * @brief Sets the count of nodes in a tree.
 *
 * @param self The tree.
 * @param count The new count to set.
 */
void tree_setCount(tree_t *self, size_t count);

/**
 * @brief Sets the root element of a tree.
 *
 * @param self The tree.
 * @param element A pointer to the new root element to set.
 */
void tree_setRootElement(tree_t *self, void *element);

#endif
