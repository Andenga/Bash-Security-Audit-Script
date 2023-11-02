#include "binary_trees.h"

/**
 * binary_tree_is_leaf - Check if a node is a leaf.
 * @node: A pointer to the node to check.
 * 
 * Return: 1 if the node is a leaf, 0 otherwise or if the node is NULL.
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

/**
 * binary_tree_leaves - Count the number of leaves in a binary tree.
 * @tree: A pointer to the root node of the tree.
 * 
 * Return: The number of leaves in the tree, or 0 if the tree is NULL.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);
    else
        return (binary_tree_is_leaf(tree) +
                binary_tree_leaves(tree->right) +
                binary_tree_leaves(tree->left));
}
