#include "binary_trees.h"

/**
 * binary_tree_sibling - finds the sibling of a node.
 *@node: pointer to the node to find the sibling.
 * Return: pointer to the sibling node.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	// Check if the input node is NULL or if it has no parent
	if (node == NULL || node->parent == NULL)
		return (NULL);

	// Check if the input node is the right child of its parent
	if (node->parent->right == node)
		return (node->parent->left);  // Return the left child as the sibling
	else
		return (node->parent->right); // Return the right child as the sibling
}

/**
 * binary_tree_uncle - function that finds the uncle of a node.
 *@node: pointer to the node to find the uncle.
 * Return: pointer to the uncle node.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	// Check if the input node is NULL
	if (node == NULL)
		return (NULL);

	// Use the binary_tree_sibling function to find the parent's other child as the uncle
	return (binary_tree_sibling(node->parent));
}
