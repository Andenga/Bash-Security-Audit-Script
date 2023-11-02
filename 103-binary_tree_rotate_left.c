#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Performs a left-rotation on a binary tree.
 * @tree: Pointer to the binary_tree_t node to be rotated.
 *
 * Return: Pointer to the new root node of the tree once rotated.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
    binary_tree_t *aux, *temp;

    if (tree == NULL)
        return (NULL);  // If the input tree is NULL, return NULL as no rotation is possible.

    if (tree->right)
    {
        temp = tree->right->left;  // Store the left child of the right subtree.
        aux = tree->right;  // Store the right child.

        aux->parent = tree->parent;  // Update the parent of the right subtree.
        aux->left = tree;  // Set the left child of the right subtree to the current tree.
        tree->parent = aux;  // Set the parent of the current tree to the right subtree.
        tree->right = temp;  // Set the right child of the current tree to the previous left child of the right subtree.

        if (temp)
            temp->parent = tree;  // Update the parent of the previous left child.

        return (aux);  // Return the new root node of the rotated tree.
    }

    return (NULL);  // If there's no right child, no rotation is performed, so return NULL.
}
