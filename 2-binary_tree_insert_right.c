#include "binary_trees.h"

/**
 * binary_tree_insert_right - insert a new node as the right child of a tree
 *
 * @parent: the parent tree node to the child
 * @value: the value of the new node
 * Return: the address of the newly created child, or NULL on failure
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (parent == NULL)
		return NULL;

	new_node = (binary_tree_t *)malloc(sizeof(binary_tree_t));
	if (new_node != NULL)
	{
		new_node->n = value, new_node->left = NULL;
		if (parent->right != NULL)
			parent->right->parent = new_node;
		new_node->right = parent->right;
		new_node->parent = parent;
		parent->right = new_node;
	}
	return new_node;
}

#if BINARY_TREE_TESTS_INCD_MAIN
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
    binary_tree_insert_right(root->left, 54);
    binary_tree_insert_right(root, 128);
    binary_tree_print(root);
    return (0);
}
#endif
