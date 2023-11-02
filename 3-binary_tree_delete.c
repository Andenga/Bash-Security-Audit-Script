#include "binary_trees.h"

/**
 * binary_tree_delete - function that deletes an entire binary tree
 * @tree: pointer to the root node of the tree to delete.
 */
void binary_tree_delete(binary_tree_t *tree)
{
    // Check if the tree is not NULL
    if (tree)
    {
        // Recursively delete the right subtree
        binary_tree_delete(tree->right);

        // Recursively delete the left subtree
        binary_tree_delete(tree->left);

        // Free the current node
        free(tree);
    }
}
