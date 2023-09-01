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
	if (tree == NULL)
		return (0);
	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * left_leaning - checks if the tree is leaning left
 *
 * @tree: input tree node
 * Return: 1 if leaning left, 0 otherwise
 */
int left_leaning(const binary_tree_t *tree)
{
	size_t l_size, r_height;

	if (tree == NULL)
		return (1);
	if (tree->left == NULL && tree->right != NULL)
		return (0);
	if (tree->right == NULL)
		return (left_leaning(tree->left));
	l_size = binary_tree_size(tree->left);
	r_height = binary_tree_height(tree->right);
	return (
		(l_size >= ((2u << r_height) - 1)) &&
		left_leaning(tree->left) &&
		left_leaning(tree->right)
	);
}

/**
 * binary_tree_is_heap - determine if a tree is a valid max heap
 *
 * @tree: the input tree node
 * Return: 1 if the tree is a max heap, 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	size_t tree_size = binary_tree_size(tree);
	size_t tree_height = binary_tree_height(tree);
	int complete = (
		(size_t)((1 << tree_height) - 1) < tree_size &&
		tree_size <= ((1u << (tree_height + 1)) - 1) &&
		left_leaning(tree)
	);

	if (
		tree == NULL || !complete ||
		(tree->left != NULL && tree->left->n > tree->n) ||
		(tree->right != NULL && tree->right->n > tree->n)
	)
		return (0);
	/* size = 2^(height + 1) - 1 */
	return (
		(tree->left == NULL || binary_tree_is_heap(tree->left)) &&
		(tree->right == NULL || binary_tree_is_heap(tree->right))
	);
}
#if BINARY_TREE_TESTS

#endif
