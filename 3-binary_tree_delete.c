#include "binary_trees.h"

/**
 * binary_tree_delete - deletes the whole binary tree at a node
 *
 * @tree: the main tree node
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree != NULL)
	{
		if (tree->parent != NULL)
		{
			if (tree == tree->parent->left)
			{
				tree->parent->left = NULL;
			}
			else if (tree == tree->parent->right)
			{
				tree->parent->right = NULL;
			}
		}
		binary_tree_delete(tree->left);
		binary_tree_delete(tree->right);
		free(tree);
	}
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

    root = binary_tree_node(NULL, 98);
    root->left = binary_tree_node(root, 12);
    root->right = binary_tree_node(root, 402);
    binary_tree_insert_right(root->left, 54);
    binary_tree_insert_right(root, 128);
    binary_tree_print(root);
    binary_tree_delete(root);
    return (0);
}
#endif
