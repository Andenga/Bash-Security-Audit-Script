#include "binary_trees.h"

/**
 * binary_tree_postorder - goes through a binary tree using post-order.
 * @tree: pointer to the root node of the tree to traverse.
 * @func: pointer to a function to call for each node.
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
    // Check if the tree and the function pointer are not NULL
    if (tree && func)
    {
        // Recursively traverse the left subtree in post-order
        binary_tree_postorder(tree->left, func);

        // Recursively traverse the right subtree in post-order
        binary_tree_postorder(tree->right, func);

        // Call the provided function on the current node's value
        func(tree->n);
    }
}
