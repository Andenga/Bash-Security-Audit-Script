#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the right-child of another node.
 * @parent: A pointer to the node to insert the right-child in.
 * @value: The value to store in the new node.
 *
 * Return: A pointer to the created node, or NULL on failure or if @parent is NULL.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
    binary_tree_t *node = NULL;

    // Check if parent is NULL
    if (parent == NULL)
        return (NULL);

    // Allocate memory for the new node
    node = malloc(sizeof(binary_tree_t));
    if (node == NULL)
        return (NULL);

    // Initialize the new node
    node->n = value;
    node->parent = parent;
    node->left = NULL;
    node->right = NULL;

    // Check if parent already has a right child
    if (parent->right == NULL)
    {
        // If not, set the new node as the right child
        parent->right = node;
    }
    else
    {
        // If yes, insert the new node between parent and its current right child
        node->right = parent->right;
        parent->right = node;
        node->right->parent = node;
    }

    return (node);
}
