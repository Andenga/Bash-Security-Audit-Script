#include "binary_trees.h"

/**
 * bst_search - Finds a node with a specific value in a binary search tree.
 * @tree: Pointer to the root of the tree to search in.
 * @value: The value to search for.
 *
 * Return: A pointer to the node with the given value if found, or NULL if not found.
 */
bst_t *bst_search(const bst_t *tree, int value)
{
    if (tree == NULL)
        return (NULL);  // If the tree is empty or the value is not found, return NULL.

    if (value == tree->n)
        return ((bst_t *)tree);  // If the current node has the desired value, return it.

    if (value < tree->n)
        return bst_search(tree->left, value);  // If the value is less than the current node's value, search in the left subtree.
    else
        return bst_search(tree->right, value);  // If the value is greater, search in the right subtree.

    return (NULL);  // Return NULL if the value is not found (this line is not necessary).
}
