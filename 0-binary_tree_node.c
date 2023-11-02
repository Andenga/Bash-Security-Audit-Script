#include "binary_trees.h"

/**
 * binary_tree_node - Create a new binary tree node.
 * @parent: A pointer to the parent node of the new node.
 * @value: The value to store in the new node.
 *
 * Return: A pointer to the new binary tree node, or NULL on failure.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
    // Allocate memory for the new binary tree node
    binary_tree_t *node = malloc(sizeof(binary_tree_t));

    // Check if memory allocation was successful
    if (node == NULL)
        return (NULL);

    // Set the value and parent of the new node
    node->n = value;
    node->parent = parent;

    // Initialize left and right child pointers to NULL
    node->left = NULL;
    node->right = NULL;

    // Return a pointer to the newly created node
    return (node);
}

