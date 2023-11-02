#include "binary_trees.h"

/**
 * binary_tree_sibling - finds the sibling of a node.
 * @node: pointer to the node to find the sibling.
 * Return: pointer to the sibling node.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
    // Check if the input node or its parent is NULL
    if (node == NULL || node->parent == NULL)
        return (NULL);

    // Check if the input node is the right child of its parent
    if (node->parent->right == node)
        return (node->parent->left);  // Return the left child as the sibling

    // If the input node is not the right child, return the right child as the sibling
    return (node->parent->right);
}
