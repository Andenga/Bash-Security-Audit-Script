#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a node as the right child of a given node.
 * @parent: Pointer to the node where the right child will be inserted.
 * @value: The value to store in the new node.
 *
 * Return: A pointer to the created node, or NULL on failure or if the parent is NULL.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
    binary_tree_t *node = NULL;

    // Check if the parent node is NULL, and return NULL if it is
    if (parent == NULL)
        return (NULL);

    // Allocate memory for the new node
    node = malloc(sizeof(binary_tree_t));
    if (node == NULL)
        return (NULL);

    // Initialize the new node with the provided value, parent, and no children
    node->n = value;
    node->parent = parent;
    node->left = NULL;
    node->right = NULL;

    // If the parent already has a right child, adjust the connections
    if (parent->right == NULL)
        parent->right = node;
    else
    {
        // If the parent already has a right child, move the current right child to the new node's right
        node->right = parent->right;
        parent->right = node;

        // Update the parent pointer of the previous right child to point to the new node
        node->right->parent = node;
    }

    // Return a pointer to the newly created node
    return (node);
}
