#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the right child of another node.
 * @parent: pointer to the node to insert the right child into.
 * @value: the value to store in the new node.
 * Return: a pointer to the created node, or NULL on failure or if no node is inserted.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
    binary_tree_t *node = NULL;

    // Check if the parent node is NULL, in which case we cannot insert a right child.
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

    // Check if the parent already has a right child.
    if (parent->right == NULL)
    {
        // If not, set the new node as the right child of the parent.
        parent->right = node;
    }
    else
    {
        // If there is an existing right child, adjust the connections to insert the new node.
        node->right = parent->right; // Make the existing right child the right child of the new node.
        parent->right = node; // Set the new node as the right child of the parent.
        node->right->parent = node; // Update the parent pointer of the previous right child.
    }

    // Return a pointer to the created node.
    return (node);
}
