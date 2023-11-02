#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a new node as the left child of a given node.
 *
 * @parent: A pointer to the node where the left child is to be inserted.
 * @value: The value to store in the new node.
 *
 * Return: A pointer to the newly created node, or NULL on failure or if parent is NULL.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
    binary_tree_t *node = NULL;

    // Check if the parent node is NULL
    if (parent == NULL)
        return (NULL);

    // Allocate memory for the new node
    node = malloc(sizeof(binary_tree_t));

    // Check if memory allocation was successful
    if (node == NULL)
        return (NULL);

    // Initialize the new node with the provided value and parent
    node->n = value;
    node->parent = parent;
    node->left = NULL;
    node->right = NULL;

    // If the parent has no left child, set the new node as the left child
    if (parent->left == NULL)
    {
        parent->left = node;
    }
    else
    {
        // If the parent already has a left child, adjust the pointers
        node->left = parent->left;
        parent->left = node;
        node->left->parent = node;
    }

    return (node);
}
