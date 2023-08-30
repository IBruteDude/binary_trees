#include "binary_trees.h"

/**
 * binary_tree_is_leaf - check if the node is leaf or not
 *
 * @node: A pointer to the node to be checked
 * Return: 1 if the node is a leaf or 0 otherwise
 */
int binary_tree_is_leaf(const binary_tree_t *node){
    return (node != NULL && node->parent != NULL && node->left == NULL && node->right == NULL);
}
#ifdef BINARY_TREE_TESTS

#endif
