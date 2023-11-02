#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in a binary tree.
 * @tree: pointer to the node to measure the depth.
 * Return: if tree is NULL or has no parent, function must return 0.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
    if (tree == NULL || tree->parent == NULL)
        return (0);
    else
    {
        // Recursively calculate the depth by moving up the tree through its parents.
        // Add 1 for each level until reaching the root.
        return (1 + binary_tree_depth(tree->parent));
    }
}
