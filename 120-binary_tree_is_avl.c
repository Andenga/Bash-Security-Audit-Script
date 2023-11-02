#include "binary_trees.h"
#include "limits.h"

/**
 * height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL, your function must return 0, else return height.
 */
size_t height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t l = 0, r = 0;

		l = tree->left ? 1 + height(tree->left) : 1; // Calculate the height of the left subtree.
		r = tree->right ? 1 + height(tree->right) : 1; // Calculate the height of the right subtree.
		return ((l > r) ? l : r); // Return the maximum height of the left and right subtrees.
	}
	return (0); // Return 0 if the tree is NULL.
}

/**
 * is_avl_helper - Checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree to check.
 * @lo: The value of the smallest node visited thus far.
 * @hi: The value of the largest node visited this far.
 *
 * Return: If the tree is a valid AVL tree, 1, otherwise, 0.
 */
int is_avl_helper(const binary_tree_t *tree, int lo, int hi)
{
	size_t lhgt, rhgt, diff;

	if (tree != NULL)
	{
		if (tree->n < lo || tree->n > hi)
			return (0); // Return 0 if a node's value is outside the valid range.
		lhgt = height(tree->left); // Get the height of the left subtree.
		rhgt = height(tree->right); // Get the height of the right subtree.
		diff = lhgt > rhgt ? lhgt - rhgt : rhgt - lhgt; // Calculate the height difference.
		if (diff > 1)
			return (0); // Return 0 if the height difference is greater than 1.
		return (is_avl_helper(tree->left, lo, tree->n - 1) &&
			is_avl_helper(tree->right, tree->n + 1, hi)); // Recursively check left and right subtrees.
	}
	return (1); // Return 1 if the tree is a valid AVL tree.
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid AVL tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0); // Return 0 if the tree is NULL.
	return (is_avl_helper(tree, INT_MIN, INT_MAX)); // Call the helper function with the valid range.
}
