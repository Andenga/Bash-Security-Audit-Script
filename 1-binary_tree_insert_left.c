#include "binary_trees.h"

/**
 * binary_tree_insert_left - a function that inserts a node as the left-child
 * @parent: A pointer to the node to insert the left-child in.
 * @value: The value to store in the new node.
 *
 * Return: A pointer to the created node, or NULL on failure or if parent is NULL.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
    binary_tree_t *node = NULL;

    // Check if the parent node is NULL, and return NULL if so
    if (parent == NULL) {
        return (NULL);
    }

    // Allocate memory for a new binary_tree_t node
    node = malloc(sizeof(binary_tree_t));

    // Check if memory allocation was successful
    if (node == NULL) {
        return (NULL);  // Return NULL if memory allocation failed
    }

    // Initialize the new node's value, parent, left, and right pointers
    node->n = value;
    node->parent = parent;
    node->left = NULL;
    node->right = NULL;

    // Check if the parent already has a left child
    if (parent->left == NULL) {
        parent->left = node;  // If not, set the new node as the left child
    } else {
        // If a left child already exists, insert the new node between them
        node->left = parent->left;
        parent->left = node;
        node->left->parent = node;
    }

    // Return a pointer to the newly created node
    return (node);
}
