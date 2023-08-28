#include "binary_trees.h"

/**
 * binary_tree_insert_left - insert a new node as the left child of a tree
 *
 * @parent: the parent tree node to the child
 * @value: the value of the new node
 * Return: the address of the newly created child, or NULL on failure
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (parent == NULL)
		return NULL;

	new_node = (binary_tree_t *)malloc(sizeof(binary_tree_t));
	if (new_node != NULL)
	{
		new_node->n = value, new_node->right = NULL;
		if (parent->left != NULL)
			parent->left->parent = new_node;
		new_node->left = parent->left;
		new_node->parent = parent;
		parent->left = new_node;
	}
	return new_node;
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

    root = binary_tree_node(NULL, 98);
    root->left = binary_tree_node(root, 12);
    root->right = binary_tree_node(root, 402);
    binary_tree_print(root);
    printf("\n");
    binary_tree_insert_left(root->right, 128);
    binary_tree_insert_left(root, 54);
    binary_tree_print(root);
    return (0);
}
#endif
