#include "binary_trees.h"

/**
 * binary_tree_height - Get the height of a binary tree.
 * @tree: A pointer to the root node of the tree.
 * 
 * Return: The height of the tree, or 0 if the tree is NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    if (tree)
    {
        int left = 1, right = 1;

        if (tree->left)
            left += binary_tree_height(tree->left);
        if (tree->right)
            right += binary_tree_height(tree->right);

        return (left > right ? left : right);
    }
    else
        return (0);
}

/**
 * binary_tree_balance - Get the balance factor of a binary tree.
 * @tree: A pointer to the root node of the tree.
 * 
 * Return: The balance factor of the tree, or 0 if the tree is NULL.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);
    return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
}
