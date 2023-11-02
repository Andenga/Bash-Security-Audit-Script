#include "binary_trees.h"

/**
 * binary_tree_inorder - function that goes through a binary tree using in-order traversal.
 * @tree: pointer to the root node of the tree to traverse.
 * @func: pointer to a function to call for each node.
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
    // Check if the tree and the function pointer are not NULL
    if (tree && func)
    {
        // Recursively traverse the left subtree in in-order
        binary_tree_inorder(tree->left, func);

        // Call the provided function on the current node's value
        func(tree->n);

        // Recursively traverse the right subtree in in-order
        binary_tree_inorder(tree->right, func);
    }
}
