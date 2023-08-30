#include "binary_trees.h"

/**
 * binary_tree_is_leaf - check if node is a leaf
 *
 * @node: input tree node
 * Return: 1 if it is a leaf, 0 otherwise
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node != NULL)
		return (node->left == NULL && node->right == NULL);
	else
		return (0);
}
#if BINARY_TREE_TESTS

#endif
