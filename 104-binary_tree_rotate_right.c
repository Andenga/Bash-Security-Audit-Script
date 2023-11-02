#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Performs a right-rotation on a binary tree.
 * @tree: Pointer to the binary_tree_t node to be rotated.
 *
 * Return: Pointer to the new root node of the tree once rotated.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
    binary_tree_t *aux, *temp;

    if (tree == NULL)
        return (NULL);  // If the input tree is NULL, return NULL as no rotation is possible.

    if (tree->left)
    {
        temp = tree->left->right;  // Store the right child of the left subtree.
        aux = tree->left;  // Store the left child.

        aux->parent = tree->parent;  // Update the parent of the left subtree.
        aux->right = tree;  // Set the right child of the left subtree to the current tree.
        tree->parent = aux;  // Set the parent of the current tree to the left subtree.
        tree->left = temp;  // Set the left child of the current tree to the previous right child of the left subtree.

        if (temp)
            temp->parent = tree;  // Update the parent of the previous right child.

        return (aux);  // Return the new root node of the rotated tree.
    }

    return (NULL);  // If there's no left child, no rotation is performed, so return NULL.
}
