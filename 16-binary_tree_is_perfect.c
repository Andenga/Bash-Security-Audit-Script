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
		int left = 0, right = 0;

		// Check if the right child exists and calculate its height
		if (tree->right)
			right = 1 + binary_tree_height(tree->right);

		// Check if the left child exists and calculate its height
		if (tree->left)
			left = 1 + binary_tree_height(tree->left);

		// Return the maximum height between left and right subtrees
		if (left > right)
			return (left);
		else
			return (right);
	}
	else
		return (0);
}

/**
 * binary_tree_size - measures the size of a binary tree.
 * @tree: pointer to the root node of the tree to measure the size.
 * Return: if tree is NULL, must return 0.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	{
		size_t n_left, n_right;

		// Recursively calculate the size of the left and right subtrees
		n_left = binary_tree_size(tree->left);
		n_right = binary_tree_size(tree->right);

		// Return the total size of the tree including the current node
		return (1 + n_left + n_right);
	}
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect.
 * @tree: pointer to the root node of the tree to check.
 * Return: if tree is NULL, function must return 0.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t h = 0, perfect_size = 0;

	if (tree == NULL)
		return (0);

	h = binary_tree_height(tree);

	// Calculate the perfect size for a binary tree of height h
	perfect_size = (1 << (h + 1)) - 1;

	// Compare the perfect size with the actual size of the tree
	if (perfect_size == binary_tree_size(tree))
		return (1);  // Return 1 if the tree is perfect
	else
		return (0);  // Return 0 if the tree is not perfect
}
