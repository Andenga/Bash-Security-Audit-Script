#include "binary_trees.h"

/**
 * binary_tree_node - creates a binary tree node with the given parent and value.
 * @parent: pointer to the parent node of the node to create.
 * @value: the value to put in the new node.
 * Return: a pointer to the new node, or NULL on memory allocation failure.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
    // Allocate memory for a new binary_tree_t node
    binary_tree_t *node = malloc(sizeof(binary_tree_t));

    // Check if memory allocation was successful
    if (node == NULL)
        return (NULL);

    // Set the value of the new node to the provided 'value'
    node->n = value;

    // Set the parent of the new node to the provided 'parent'
    node->parent = parent;

    // Initialize the left and right child pointers to NULL
    node->left = NULL;
    node->right = NULL;

    // Return a pointer to the newly created node
    return (node);
}
