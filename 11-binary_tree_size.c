#include "binary_trees.h"

/**
 * binary_tree_size - determine the size of a binary tree
 *
 * @tree: input tree node
 * Return: the size of the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 1;

	if (tree == NULL)
		return (0);
	if (tree->left != NULL)
		size += binary_tree_size(tree->left);
	if (tree->right != NULL)
		size += binary_tree_size(tree->right);
	return (size);
}
#if BINARY_TREE_TESTS
#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	binary_tree_t *root;
	size_t size;

	root = binary_tree_node(NULL, 98);
	root->left = binary_tree_node(root, 12);
	root->right = binary_tree_node(root, 402);
	binary_tree_insert_right(root->left, 54);
	binary_tree_insert_right(root, 128);
	binary_tree_print(root);

	size = binary_tree_size(root);
	printf("Size of %d: %lu\n", root->n, size);
	size = binary_tree_size(root->right);
	printf("Size of %d: %lu\n", root->right->n, size);
	size = binary_tree_size(root->left->right);
	printf("Size of %d: %lu\n", root->left->right->n, size);
	return (0);
}
#endif
