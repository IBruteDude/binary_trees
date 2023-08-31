#include "binary_trees.h"

/**
 * binary_tree_depth - determine the depth of a node inside a tree
 *
 * @tree: input tree node
 * Return: the depth of the node
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (tree == NULL)
		return (0);
	while (tree->parent != NULL)
		tree = tree->parent, depth++;
	return (depth);
}

/**
 * binary_trees_ancestor - find the lowest common ancestor of two tree nodes
 *
 * @first: the first node
 * @second: the second node
 * Return: the node address if found, NULL otherwise
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
									const binary_tree_t *second)
{
	binary_tree_t **first_bloodline, **second_bloodline, *current;
	size_t f_i = 0, s_i = 0;

	if (first == NULL || second == NULL)
		return (NULL);
	first_bloodline = calloc(binary_tree_depth(first) + 1,
							sizeof(binary_tree_t *));
	second_bloodline = calloc(binary_tree_depth(second) + 1,
							sizeof(binary_tree_t *));
	current = (binary_tree_t *)first;
	while (current != NULL)
		first_bloodline[f_i++] = current, current = current->parent;
	current = (binary_tree_t *)second;
	while (current != NULL)
		second_bloodline[s_i++] = current, current = current->parent;

	if (first_bloodline[f_i - 1] != second_bloodline[s_i - 1])
		return (NULL);

	while (first_bloodline[--f_i] == second_bloodline[--s_i])
		current = first_bloodline[f_i];
	return (current);
}

#if BINARY_TREE_TESTS
#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * launch_test - Test ancestor function and print informations
 *
 * @n1: First node
 * @n2: Second node
 */
void launch_test(binary_tree_t *n1, binary_tree_t *n2)
{
	binary_tree_t *ancestor;

	ancestor = binary_trees_ancestor(n1, n2);
	printf("Ancestor of [%d] & [%d]: ", n1->n, n2->n);
	if (!ancestor)
		printf("(nil)\n");
	else
		printf("%d\n", ancestor->n);
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
	root->left->right = binary_tree_node(root->left, 54);
	root->right->right = binary_tree_node(root->right, 128);
	root->left->left = binary_tree_node(root->left, 10);
	root->right->left = binary_tree_node(root->right, 45);
	root->right->right->left = binary_tree_node(root->right->right, 92);
	root->right->right->right = binary_tree_node(root->right->right, 65);
	binary_tree_print(root);

	launch_test(root->left, root->right);
	launch_test(root->right->left, root->right->right->right);
	launch_test(root->right->right, root->right->right->right);
	return (0);
}
#endif
