#include "binary_trees.h"
/**
 * binary_tree_balance - measures the balance factor of a binary tree
 *
 * @tree: pointer to the root node of the tree to measure the balance factor
 * Return: balance or 0 if the tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
    int balance;
    balance = 0;

    if(tree == NULL)
    {
        return (0);
    }

    if (tree->left != NULL)
    {
        balance += 1;
    }

    if (tree->right != NULL)
    {
        balance += 1;
    }

    if (balance == 1)
    {
        balance *= -1;
    }
    return (balance);
}

#ifdef BINARY_TREE_TESTS

#endif
