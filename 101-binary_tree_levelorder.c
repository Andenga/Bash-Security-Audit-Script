#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL, your function must return 0. Otherwise, the height.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    if (tree)
    {
        int left = 0, right = 0;

        if (tree->right)
            right = 1 + binary_tree_height(tree->right);
        if (tree->left)
            left = 1 + binary_tree_height(tree->left);

        // Return the greater of the left and right heights
        if (left > right)
            return (left);
        else
            return (right);
    }
    else
        return (0);
}

/**
 * print_at_level - Prints nodes at a specific level of the tree.
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to a function to call for each node.
 * @level: The level of the tree to print.
 */
void print_at_level(const binary_tree_t *tree, void (*func)(int), int level)
{
    if (tree && func)
    {
        if (level == 1)
            func(tree->n);
        else
        {
            // Recursively print nodes at the specified level
            print_at_level(tree->left, func, level - 1);
            print_at_level(tree->right, func, level - 1);
        }
    }
}

/**
 * binary_tree_levelorder - Goes through a binary tree in level-order traversal.
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to a function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
    size_t h = 0, i = 1;

    if (tree && func)
    {
        h = binary_tree_height(tree);

        // Iterate through each level of the tree and print nodes
        while (i <= h + 1)
        {
            print_at_level(tree, func, i);
            i++;
        }
    }
}
