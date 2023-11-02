#include "binary_trees.h"

/**
 * binary_tree_is_leaf - Checks if a given node is a leaf.
 * @node: A pointer to the node to check.
 * 
 * Return: 1 if the node is a leaf, otherwise 0.
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
    if (node == NULL)
        return (0);

    if (node->right == NULL && node->left == NULL)
        return (1);
    else
        return (0);
}
