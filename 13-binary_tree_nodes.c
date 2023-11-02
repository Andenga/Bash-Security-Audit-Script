#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes with at least 1 child in a binary tree.
 * @tree: pointer to the root node of the tree to count the number of nodes.
 * Return: If tree is NULL, the function must return 0.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	
	// If the current node has at least one child (left or right),
	// increment the count by 1 and recursively count the nodes in left and right subtrees.
	if (tree->right != NULL || tree->left != NULL)
		return  (1 + binary_tree_nodes(tree->right) + binary_tree_nodes(tree->left));

	// If the current node has no children, return 0.
	return (0);
}
