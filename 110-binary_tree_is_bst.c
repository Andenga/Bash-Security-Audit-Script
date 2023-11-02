#include "binary_trees.h"

/**
 * find_node - Function to find a node in a binary tree.
 * @root: The root of the tree to evaluate.
 * @node: The node to find.
 * 
 * Return: 1 if the node exists, 0 if not.
 */
int find_node(binary_tree_t *root, binary_tree_t *node)
{
    if (root == NULL)
        return (0);
    if (node == root)
        return (1);
    if (node->n < root->n)
        return find_node(root->left, node);
    if (node->n > root->n)
        return find_node(root->right, node);
    return (0);
}

/**
 * cross_tree - Function to cross the tree, checking if each node exists correctly.
 * @root: The root node of the tree.
 * @node: The current node to evaluate.
 * 
 * Return: 1 if it is a binary search tree, 0 if not.
 */
int cross_tree(binary_tree_t *root, binary_tree_t *node)
{
    if (root && node)
    {
        int aux = 0;

        aux = find_node(root, node);
        if (node->left)
            aux &= cross_tree(root, node->left);
        if (node->right)
            aux &= cross_tree(root, node->right);
        return (aux);
    }
    return (0);
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a correct binary search tree (BST).
 * @tree: The tree to check.
 * 
 * Return: 1 if it is a correct BST, 0 if not.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);
    return cross_tree((binary_tree_t *)tree, (binary_tree_t *)tree);
}
