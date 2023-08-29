#include "binary_trees.h"

/**
 * binary_tree_is_root - check if node is a root of a tree
 *
 * @node: input tree node
 * Return: 1 if it is a root of a tree, 0 otherwise
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	return (node != NULL && node->parent == NULL);
}
#ifdef BINARY_TREE_TESTS

#endif
