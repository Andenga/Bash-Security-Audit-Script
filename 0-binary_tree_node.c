#include "binary_trees.h"

/**
 * binary_tree_node - Creates a new binary tree node.
 *
 * @parent: A pointer to the parent node of the new node.
 * @value: The value to be stored in the new node.
 *
 * Return: A pointer to the new node or NULL if memory allocation fails.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
    // Allocate memory for a new binary tree node
    binary_tree_t *node = malloc(sizeof(binary_tree_t));

    // Check if memory allocation was successful
    if (node == NULL)
        return (NULL);

    // Initialize the node's data and pointers
    node->n = value;         // Set the value
    node->parent = parent;   // Set the parent pointer
    node->left = NULL;       // Initialize the left child as NULL
    node->right = NULL;      // Initialize the right child as NULL

    // Return a pointer to the newly created node
    return (node);
}

