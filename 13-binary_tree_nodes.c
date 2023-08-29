#include "binary_trees.h"

/**
 * binary_tree_nodes - determine the number of nodes in a tree
 *
 * @tree: input tree node
 * Return: the number of nodes in the tree
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (!(tree->left == NULL && tree->right == NULL) +
		binary_tree_nodes(tree->left) +
		binary_tree_nodes(tree->right));
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
	size_t nodes;

	root = binary_tree_node(NULL, 98);
	root->left = binary_tree_node(root, 12);
	root->right = binary_tree_node(root, 402);
	binary_tree_insert_right(root->left, 54);
	binary_tree_insert_right(root, 128);
	binary_tree_print(root);

	nodes = binary_tree_nodes(root);
	printf("Nodes in %d: %lu\n", root->n, nodes);
	nodes = binary_tree_nodes(root->right);
	printf("Nodes in %d: %lu\n", root->right->n, nodes);
	nodes = binary_tree_nodes(root->left->right);
	printf("Nodes in %d: %lu\n", root->left->right->n, nodes);
	return (0);
}
#endif
