#include "binary_trees.h"

/**
 * binary_tree_depth - determine the depth of a node inside a tree
 *
 * @tree: input tree node
 * Return: the depth of the node
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	while (tree->parent != NULL)
		tree = tree->parent, depth++;
	return (depth);
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
	size_t depth;

	root = binary_tree_node(NULL, 98);
	root->left = binary_tree_node(root, 12);
	root->right = binary_tree_node(root, 402);
	binary_tree_insert_right(root->left, 54);
	binary_tree_insert_right(root, 128);
	binary_tree_print(root);

	depth = binary_tree_depth(root);
	printf("Depth of %d: %lu\n", root->n, depth);
	depth = binary_tree_depth(root->right);
	printf("Depth of %d: %lu\n", root->right->n, depth);
	depth = binary_tree_depth(root->left->right);
	printf("Depth of %d: %lu\n", root->left->right->n, depth);
	return (0);
}
#endif
