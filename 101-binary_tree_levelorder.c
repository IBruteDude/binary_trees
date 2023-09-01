#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>
#ifdef max
#undef max
#endif
/**
 * max - find the maximum of two numbers
 *
 * @a: the first number
 * @b: the second number
 * Return: the max of the two
 */
size_t max(size_t a, size_t b)
{
	if (a >= b)
		return (a);
	return (b);
}

/**
 * binary_tree_height - determine the height of the tree
 *
 * @tree: input tree node
 * Return: the height of the tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
		return (0);
	return (1 + max(
		binary_tree_height(tree->left),
		binary_tree_height(tree->right)
	));
}

/**
 * binary_tree_levelorder - traverse a binary tree using level-order traversal
 *
 * @tree: pointer to the tree node of the tree to traverse
 * @func: pointer to a function to call for each node.
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	heap_t *pnode = NULL, **node_level;
	size_t i, height, level_size;

	if (tree == NULL || func == NULL)
		return;
	height = binary_tree_height(tree);
	node_level = calloc(1u << height, sizeof(pnode));
	*node_level = (binary_tree_t *)tree, level_size = 1;
	while (level_size <= (1u << height))
	{
		for (i = 0; i < level_size; i++)
			if (node_level[i] != NULL)
				func(node_level[i]->n);
		if (i < (1u << height))
			while (i--)
				node_level[2 * i + 1] = node_level[i]->right,
				node_level[2 * i] = node_level[i]->left;
		level_size <<= 1;
	}
	free(node_level);
}

#if BINARY_TREE_TESTS
#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * print_num - Prints a number
 *
 * @n: Number to be printed
 */
void print_num(int n)
{
	printf("%d\n", n);
}

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
	root->left->left = binary_tree_node(root->left, 6);
	root->left->right = binary_tree_node(root->left, 56);
	root->right->left = binary_tree_node(root->right, 256);
	root->right->right = binary_tree_node(root->right, 512);

	root->left->left->left = binary_tree_node(root->left->left, 7);
	root->left->right->left = binary_tree_node(root->left->right, 57);
	root->right->left->left = binary_tree_node(root->right->left, 257);
	root->right->right->left = binary_tree_node(root->right->right, 513);

	root->left->left->right = binary_tree_node(root->left->left, 8);
	root->left->right->right = binary_tree_node(root->left->right, 58);
	root->right->left->right = binary_tree_node(root->right->left, 258);
	root->right->right->right = binary_tree_node(root->right->right, 514);

	binary_tree_print(root);
	binary_tree_levelorder(root, &print_num);
	binary_tree_delete(root);
	return (0);
}
#endif
