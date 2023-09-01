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
 * heap_insert - inserts a new value into a max heap
 *
 * @root: the root of the heap
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
	if (node->left == NULL)
	{
		if (value < node->n)
		{
			node->left = binary_tree_node(node, value);
			return (node->left);
		}
		*root = binary_tree_node((*root)->parent, value);
		(*root)->left = node;
		return (*root);
	}
	if (node->right == NULL)
	{
		if (value < node->n)
		{
			node->right = binary_tree_node(node, value);
			return (node->right);
		}
		*root = binary_tree_node((*root)->parent, value);
		(*root)->right = node;
		return (*root);
	}
	r_h = binary_tree_height(node->right) + 1;
	if (
		(binary_tree_height(node->left) + 1 == r_h) &&
		(binary_tree_size(node->right) != ((2u << r_h) - 1))
	)
		return (heap_insert(&node->right, value));
	return (heap_insert(&node->left, value));
}

#if BINARY_TREE_TESTS
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
    return (0);
}
#endif
