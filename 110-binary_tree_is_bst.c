#include "binary_trees.h"

/**
 * find_node - Function to find a node in a tree.
 * @root: Root of the tree to evaluate.
 * @node: Node to find.
 *
 * Return: 1 if the node exists, 0 if not.
 */
int find_node(binary_tree_t *root, binary_tree_t *node)
{
    if (root == NULL)
        return (0);  // If the root is NULL, the node does not exist in the tree.

    if (node == root)
        return (1);  // If the given node matches the current root, it exists in the tree.

    if (node->n < root->n)
        return (find_node(root->left, node));  // Recursively search the left subtree if the node value is less than the current root's value.

    if (node->n > root->n)
        return (find_node(root->right, node));  // Recursively search the right subtree if the node value is greater than the current root's value.

    return (0);  // If none of the conditions are met, the node does not exist in the tree.
}

/**
 * croos_tree - Crosses the tree, checking if each node exists correctly.
 * @root: Root node of the tree.
 * @node: Current node to evaluate.
 *
 * Return: 1 if it is a valid Binary Search Tree (BST), 0 if not.
 */
int croos_tree(binary_tree_t *root, binary_tree_t *node)
{
    if (root && node)
    {
        int aux = 0;

        aux = find_node(root, node);  // Check if the current node exists in the tree.

        if (node->left)
            aux &= croos_tree(root, node->left);  // Recursively check the left subtree.

        if (node->right)
            aux &= croos_tree(root, node->right);  // Recursively check the right subtree.

        return (aux);  // Return 1 if the current node and its subtrees exist in the tree, 0 otherwise.
    }

    return (0);  // If either the root or node is NULL, it's not a valid BST.
}

/**
 * binary_tree_is_bst - Checks if a tree is a correctly ordered Binary Search Tree (BST).
 * @tree: Tree to check.
 *
 * Return: 1 if it is a valid BST, 0 if not.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);  // If the input tree is NULL, it's not a valid BST.

    return (croos_tree((binary_tree_t *)tree, (binary_tree_t *)tree));  // Start checking the tree from its root.
}
