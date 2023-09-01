#include "binary_trees.h"

/**
 * binary_tree_rotate_right - perform a right rotatation on a tree node
 *
 * @tree: the input tree node
 * Return: the new node in its place
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new_node = tree;

	if (tree == NULL)
		return (NULL);
	if (tree->left != NULL)
	{
		new_node = tree->left;
		tree->left = new_node->right;
		new_node->right = tree;
		if (tree->left != NULL)
			tree->left->parent = tree;
		new_node->parent = tree->parent;
		tree->parent = new_node;
	}
	return (new_node);
}
#if BINARY_TREE_TESTS
#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: 0 on success, error code on failure
 */
int main(void)
{
	binary_tree_t *root;

	root = binary_tree_node(NULL, 98);
	root->left = binary_tree_node(root, 64);
	root->left->left = binary_tree_node(root->left, 32);
	binary_tree_print(root);
	printf("Rotate-right %d\n", root->n);
	root = binary_tree_rotate_right(root);
	binary_tree_print(root);
	printf("\n");

	root->left->left = binary_tree_node(root->left, 20);
	root->left->right = binary_tree_node(root->left, 56);
	binary_tree_print(root);
	printf("Rotate-right %d\n", root->n);
	root = binary_tree_rotate_right(root);
	binary_tree_print(root);
	return (0);
}
#endif
