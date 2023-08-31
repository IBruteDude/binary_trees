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
 * binary_tree_balance - calculate the balance factor of a tree
 *
 * @tree: the input tree node
 * Return: the balance factor of the binary tree
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	return (
		((tree->left != NULL) + binary_tree_height(tree->left)) -
		((tree->right != NULL) + binary_tree_height(tree->right))
	);
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
	int balance;

	root = binary_tree_node(NULL, 98);
	root->left = binary_tree_node(root, 12);
	root->right = binary_tree_node(root, 402);
	binary_tree_insert_right(root->left, 54);
	binary_tree_insert_right(root, 128);
	binary_tree_insert_left(root, 45);
	binary_tree_insert_right(root->left, 50);
	binary_tree_insert_left(root->left->left, 10);
	binary_tree_insert_left(root->left->left->left, 8);
	binary_tree_print(root);

	balance = binary_tree_balance(root);
	printf("Balance of %d: %+d\n", root->n, balance);
	balance = binary_tree_balance(root->right);
	printf("Balance of %d: %+d\n", root->right->n, balance);
	balance = binary_tree_balance(root->left->left->right);
	printf("Balance of %d: %+d\n", root->left->left->right->n, balance);
	return (0);
}
#endif
