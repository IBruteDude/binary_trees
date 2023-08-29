#include "binary_trees.h"

/**
 * binary_tree_node - creates a new child tree node
 *
 * @parent: the parent tree node to the child
 * @value: the value of the new node
 * Return: the address of the newly created child, or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = (binary_tree_t *)malloc(sizeof(binary_tree_t));

	if (new_node != NULL)
	{
		new_node->n = value;
		new_node->left = new_node->right = NULL;
		new_node->parent = parent;
	}
	return (new_node);
}

#if BINARY_TREE_TESTS_INCD_MAIN
#include <stdlib.h>
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	binary_tree_t *root;

	root = binary_tree_node(NULL, 98);

	root->left = binary_tree_node(root, 12);
	root->left->left = binary_tree_node(root->left, 6);
	root->left->right = binary_tree_node(root->left, 16);

	root->right = binary_tree_node(root, 402);
	root->right->left = binary_tree_node(root->right, 256);
	root->right->right = binary_tree_node(root->right, 512);

	binary_tree_print(root);
	return (0);
}
#endif
