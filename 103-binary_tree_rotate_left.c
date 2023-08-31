#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 *
 * @tree: a pointer to the root node of the tree to rotate
 * Return: a pointer to the new root node of the tree once rotated
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
    binary_tree_t *newRoot;

	if (tree == NULL || tree->right == NULL)
	{
		return (NULL);
	}
	newRoot = tree->right;
	tree->right = newRoot->left;
	if (newRoot->left != NULL)
	{
		newRoot->left->parent = tree;
	}
	newRoot->left = tree;
	newRoot->parent = tree->parent;
	tree->parent = newRoot;
	return (newRoot);
}
