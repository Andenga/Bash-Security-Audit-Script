#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left child of another node.
 * @parent: pointer to the node to insert the left child into.
 * @value: the value to store in the new node.
 * Return: a pointer to the created node, or NULL on failure or if no node is inserted.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
    binary_tree_t *node = NULL;

    // Check if the parent node is NULL, in which case we cannot insert a left child.
    if (parent == NULL)
        return (NULL);

    // Allocate memory for the new node.
    node = malloc(sizeof(binary_tree_t));

    // Check if memory allocation was successful.
    if (node == NULL)
        return (NULL);

    // Set the value and parent of the new node, and initialize left and right children as NULL.
    node->n = value;
    node->parent = parent;
    node->left = NULL;
    node->right = NULL;

    // Check if the parent already has a left child.
    if (parent->left == NULL)
    {
        // If not, set the new node as the left child of the parent.
        parent->left = node;
    }
    else
    {
        // If there is an existing left child, adjust the connections to insert the new node.
        node->left = parent->left; // Make the existing left child the left child of the new node.
        parent->left = node; // Set the new node as the left child of the parent.
        node->left->parent = node; // Update the parent pointer of the previous left child.
    }

    // Return a pointer to the created node.
    return (node);
}
