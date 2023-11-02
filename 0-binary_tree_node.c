#include "binary_trees.h"

/**
 * binary_tree_node - Creates a new binary tree node.
 * @parent: A pointer to the parent node of the node to create.
 * @value: The value to assign to the new node.
 * Return: A pointer to the new node, or NULL if it cannot be created.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
    // Allocate memory for a new binary_tree_t node
    binary_tree_t *node = malloc(sizeof(binary_tree_t));

    // Check if memory allocation was successful
    if (node == NULL)
        return (NULL);

    // Initialize the node with the provided value and parent node
    node->n = value;
    node->parent = parent;
    node->left = NULL;
    node->right = NULL;

    // Return a pointer to the new node
    return (node);
}

