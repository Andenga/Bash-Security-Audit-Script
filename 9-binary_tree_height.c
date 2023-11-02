#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree.
 * @tree: pointer to the root node of the tree to measure the height.
 * Return: if tree is NULL, your function must return 0.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    // Check if the tree is not empty (not NULL)
    if (tree)
    {
        int left = 0, right = 0;  // Initialize variables to track left and right subtree heights

        // Check if there is a right subtree, and if so, calculate its height recursively and add 1
        if (tree->right)
            right = 1 + binary_tree_height(tree->right);

        // Check if there is a left subtree, and if so, calculate its height recursively and add 1
        if (tree->left)
            left = 1 + binary_tree_height(tree->left);

        // Compare the heights of the left and right subtrees and return the larger height
        if (left > right)
            return (left);
        else
            return (right);
    }
    else
    {
        // If the tree is NULL, return 0, as the height of an empty tree is 0
        return (0);
    }
}
