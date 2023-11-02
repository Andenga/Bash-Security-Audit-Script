#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree.
 * @tree: pointer to the root node of the tree to measure the height.
 * Return: if tree is NULL, your function must return 0.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		int left = 1, right = 1;

		// If the right child exists, calculate the height of the right subtree
		if (tree->right)
			right += binary_tree_height(tree->right);

		// If the left child exists, calculate the height of the left subtree
		if (tree->left)
			left += binary_tree_height(tree->left);

		// Return the maximum height between left and right subtrees
		if (left > right)
			return (left);
		else
			return (right);
	}
	else
		// If the tree is NULL, return 0
		return (0);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree.
 * @tree: pointer to the root node of the tree to measure the balance factor.
 * Return: If tree is NULL, return 0
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	// Calculate the balance factor by subtracting the height of the right subtree
	// from the height of the left subtree
	return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
}
