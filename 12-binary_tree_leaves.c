#include "binary_trees.h"

/**
 * binary_tree_leaves - determine the number of leaves in a tree
 *
 * @tree: input tree node
 * Return: the number of leaves in the tree
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return ((tree->left == NULL && tree->right == NULL) +
		binary_tree_leaves(tree->left) +
		binary_tree_leaves(tree->right));
}
#ifdef BINARY_TREE_TESTS
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
	size_t leaves;

	root = binary_tree_node(NULL, 98);
	root->left = binary_tree_node(root, 12);
	root->right = binary_tree_node(root, 402);
	binary_tree_insert_right(root->left, 54);
	binary_tree_insert_right(root, 128);
	binary_tree_print(root);

	leaves = binary_tree_leaves(root);
	printf("Leaves in %d: %lu\n", root->n, leaves);
	leaves = binary_tree_leaves(root->right);
	printf("Leaves in %d: %lu\n", root->right->n, leaves);
	leaves = binary_tree_leaves(root->left->right);
	printf("Leaves in %d: %lu\n", root->left->right->n, leaves);
	return (0);
}
#endif
