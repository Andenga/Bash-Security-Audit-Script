#include "binary_trees.h"

/**
 * binary_tree_node - Create a binary tree node with the given value and parent.
 * @parent: Pointer to the parent node of the node to create.
 * @value: The value to put in the new node.
 *
 * This function creates a new binary tree node with the provided value and parent.
 *
 * Return: A pointer to the new node, or NULL if memory allocation fails.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
    // Allocate memory for the new binary tree node
    binary_tree_t *node = malloc(sizeof(binary_tree_t));

    // Check if memory allocation was successful
    if (node == NULL)
        return (NULL);

    // Initialize the node with the provided value and parent
    node->n = value;     // Set the value of the node
    node->parent = parent; // Set the parent of the node
    node->left = NULL;   // Initialize the left child as NULL
    node->right = NULL;  // Initialize the right child as NULL

    // Return a pointer to the newly created node
    return (node);
}
#include "binary_trees.h"

/**
 * binary_tree_node - function that creates a binary tree node.
 *@parent: is a pointer to the parent node of the node to create.
 *@value: is the value to put in the new node.
 * Return:Your function must return a pointer to the new node or NULL if no.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node = malloc(sizeof(binary_tree_t));

	if (node == NULL)
		return (NULL);
	node->n = value;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;
	return (node);
}
