#include "binary_trees.h"

/**
 * binary_tree_node - Function that creates a binary tree node.
 * @parent: Pointer to the parent node of the node to create.
 * @value: Value to put in the new node.
 *
 * Return: A pointer to the new node, or NULL if allocation fails.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
    // Allocate memory for a new binary tree node
    binary_tree_t *node = malloc(sizeof(binary_tree_t));

    // Check if memory allocation was successful
    if (node == NULL)
        return (NULL);

    // Initialize the new node with the provided value and parent node
    node->n = value;
    node->parent = parent;
    node->left = NULL;
    node->right = NULL;

    // Return a pointer to the newly created node
    return (node);
}
