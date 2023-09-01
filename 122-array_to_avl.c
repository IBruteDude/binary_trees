#include "binary_trees.h"

/**
 * array_to_avl - populate an AVL tree from an array
 *
 * @array: input integers array
 * @size: the array's size
 * Return: the root of the created AVL
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *avl;

	if (size == 0 || array == NULL)
		return (NULL);
	avl = malloc(sizeof(*avl));
	while (size--)
		avl_insert(avl, *(array++));
	return (avl);
}
#if BINARY_TREE_TESTS
#include <stdlib.h>
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: 0 on success, error code on failure
 */
int main(void)
{
	avl_t *tree;
	int array[] = {
		79, 47, 68, 87, 84, 91, 21, 32, 34, 2,
		20, 22, 98, 1, 62, 95
	};
	size_t n = sizeof(array) / sizeof(array[0]);

	tree = array_to_avl(array, n);
	if (!tree)
		return (1);
	binary_tree_print(tree);
	return (0);
}
#endif
