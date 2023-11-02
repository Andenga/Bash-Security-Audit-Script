#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds the sibling of a given node.
 * @node: A pointer to the node to find the sibling of.
 * 
 * Return: A pointer to the sibling node, or NULL if the node has no sibling.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
    if (node == NULL || node->parent == NULL)
        return (NULL);
    if (node->parent->right == node)
        return (node->parent->left);
    else
        return (node->parent->right);
}

/**
 * binary_tree_uncle - Finds the uncle of a given node.
 * @node: A pointer to the node to find the uncle of.
 * 
 * Return: A pointer to the uncle node, or NULL if the node has no uncle.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
    if (node == NULL)
        return (NULL);
    return (binary_tree_sibling(node->parent));
}
