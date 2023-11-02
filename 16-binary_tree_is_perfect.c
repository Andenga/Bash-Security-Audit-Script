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
        int left_height = 0, right_height = 0;

        if (tree->left)
            left_height = 1 + binary_tree_height(tree->left);
        if (tree->right)
            right_height = 1 + binary_tree_height(tree->right);

        return (left_height > right_height ? left_height : right_height);
    }
    else
        return (0);
}

/**
 * binary_tree_size - Get the size of a binary tree.
 * @tree: A pointer to the root node of the tree.
 * 
 * Return: The size of the tree, or 0 if the tree is NULL.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
    if (tree)
    {
        size_t left_size = binary_tree_size(tree->left);
        size_t right_size = binary_tree_size(tree->right);
        
        return (1 + left_size + right_size);
    }
    else
        return (0);
}

/**
 * binary_tree_is_perfect - Check if a binary tree is perfect.
 * @tree: A pointer to the root node of the tree.
 * 
 * Return: 1 if the tree is perfect, 0 otherwise or if the tree is NULL.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    size_t tree_height = binary_tree_height(tree);
    size_t perfect_size = (1 << (tree_height + 1)) - 1;

    return (perfect_size == binary_tree_size(tree));
}
