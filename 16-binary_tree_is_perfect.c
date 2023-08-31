#include "binary_trees.h"

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

/**
 * binary_tree_is_perfect - determine if a tree is perfect
 *
 * @tree: the input tree node
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t tree_size = binary_tree_size(tree);
	size_t tree_height = binary_tree_height(tree);

	if (tree == NULL)
		return (0);
#ifdef RECURSIVE_DEFINITION
	return ((tree->left == NULL && tree->right == NULL) ||
		(
			(tree->left != NULL && tree->right != NULL) &&
			(
				binary_tree_is_perfect(tree->left) &&
				binary_tree_is_perfect(tree->right)
			) &&
			(binary_tree_height(tree->left) == binary_tree_height(tree->right))
		)
	);
#else
	/* size = 2^(height + 1) - 1 */
	return (
		tree_size == (size_t)((1 << (tree_height + 1)) - 1)
	);
#endif
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
	int perfect;

	root = binary_tree_node(NULL, 98);
	root->left = binary_tree_node(root, 12);
	root->right = binary_tree_node(root, 402);
	binary_tree_insert_right(root->left, 54);
	binary_tree_insert_right(root, 128);
	root->left->left = binary_tree_node(root->left, 10);
	root->right->left = binary_tree_node(root->right, 10);

	binary_tree_print(root);
	perfect = binary_tree_is_perfect(root);
	printf("Perfect: %d\n\n", perfect);

	root->right->right->left = binary_tree_node(root->right->right, 10);
	binary_tree_print(root);
	perfect = binary_tree_is_perfect(root);
	printf("Perfect: %d\n\n", perfect);

	root->right->right->right = binary_tree_node(root->right->right, 10);
	binary_tree_print(root);
	perfect = binary_tree_is_perfect(root);
	printf("Perfect: %d\n", perfect);
	return (0);
}
#endif
