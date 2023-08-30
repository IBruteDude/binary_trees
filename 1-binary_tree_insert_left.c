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
	 binary_tree_t *newNode;
    newNode = malloc(sizeof(binary_tree_t));

    if (newNode == NULL || parent == NULL)
    {
        return (NULL);
    }

    newNode->n = value;
    newNode->parent = parent;

    if (parent->left != NULL)
    {
        newNode->left = parent->left;
        free(parent->left);
        newNode->left->parent = newNode;
    }
    parent->left = newNode;
    return (newNode);
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
