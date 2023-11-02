#include "binary_trees.h"

/**
 * binary_tree_node - function that creates a binary tree node.
 * @parent: A pointer to the parent node of the node to create.
 * @value: The value to put in the new node.
 *
 * Return: A pointer to the new node or NULL if memory allocation fails.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
    // Allocate memory for a new binary_tree_t node
    binary_tree_t *node = malloc(sizeof(binary_tree_t));

    // Check if memory allocation was successful
    if (node == NULL) {
        return (NULL);  // Return NULL if memory allocation failed
    }

    // Initialize the new node's value, parent, left, and right pointers
    node->n = value;    // Set the value of the new node
    node->parent = parent; // Set the parent of the new node
    node->left = NULL;     // Initialize the left child as NULL
    node->right = NULL;    // Initialize the right child as NULL

    // Return a pointer to the newly created node
    return (node);
}
