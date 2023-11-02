#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree.
 * @tree: pointer to the root node of the tree to measure the size.
 * Return: if tree is NULL, must return 0.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);
    else
    {
        size_t n_left, n_right;

        // Recursively calculate the size of the left and right subtrees
        n_left = binary_tree_size(tree->left);
        n_right = binary_tree_size(tree->right);

        // The size of the tree is the sum of the sizes of the left and right subtrees
        // plus 1 for the current node.
        return (1 + n_left + n_right);
    }
}
