#include "binary_trees.h"
#if 0
#include "binary_tree_print.c"
#include "0-binary_tree_node.c"
#endif
#include <stdio.h>
#include <stdint.h>

#define H(x) binary_tree_height(x)
#define S(x) binary_tree_size(x)

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
 * heap_insert - inserts a new value into a max heap
 *
 * @root: the address of the root of the heap
 * @value: the value to insert into the heap
 * Return: the address of the created node, NULL otherwise
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *node;
	size_t r_h;

	if (root == NULL)
		return (NULL);
	if (*root == NULL)
	{
		*root = binary_tree_node(*root, value);
		return (*root);
	}
	node = *root;
	r_h = binary_tree_height(node->right);
	if (value <= node->n)
	{
		if (node->left == NULL)
			return ((*root)->left = binary_tree_node((*root), value));
		if (node->right == NULL)
			return ((*root)->right = binary_tree_node((*root), value));
		if ((H(node->left) > r_h) && (S(node->left) == ((2u << H(node->left)) - 1)))
			return (heap_insert(&(*root)->right, value));
		return (heap_insert(&(*root)->left, value));
	}
	node = binary_tree_node((*root)->parent, value);
	node->left = (*root);
	if ((*root)->parent != NULL && (*root)->parent->left == node)
		(*root)->parent->left = node;
	if ((*root)->parent != NULL && (*root)->parent->right == node)
		(*root)->parent->right = node;
	return (*root) = (*root)->parent = node;
}


#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: 0 on success, error code on failure
 */
int main(void)
{
	heap_t *root;
	heap_t *node;

	root = NULL;
	node = heap_insert(&root, 98);
	printf("Inserted: %d\n", node->n);
	binary_tree_print(root);
	node = heap_insert(&root, 402);
	printf("\nInserted: %d\n", node->n);
	binary_tree_print(root);
	node = heap_insert(&root, 12);
	printf("\nInserted: %d\n", node->n);
	binary_tree_print(root);
	node = heap_insert(&root, 46);
	printf("\nInserted: %d\n", node->n);
	binary_tree_print(root);
	node = heap_insert(&root, 128);
	printf("\nInserted: %d\n", node->n);
	binary_tree_print(root);
	node = heap_insert(&root, 256);
	printf("\nInserted: %d\n", node->n);
	binary_tree_print(root);
	node = heap_insert(&root, 512);
	printf("\nInserted: %d\n", node->n);
	binary_tree_print(root);
	node = heap_insert(&root, 50);
	printf("\nInserted: %d\n", node->n);
	binary_tree_print(root);
}
