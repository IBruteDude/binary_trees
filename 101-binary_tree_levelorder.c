#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * binary_tree_levelorder - traverse a binary tree using level-order traversal
 *
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node.
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
	{
		return;
	}
	if (tree->parent == NULL)
	{
		func(tree->n);
	}
	if (tree->left != NULL)
	{
		func(tree->left->n);
	}
	if (tree->right != NULL)
	{
		func(tree->right->n);
	}
	binary_tree_levelorder(tree->left, func);
	binary_tree_levelorder(tree->right, func);
}
