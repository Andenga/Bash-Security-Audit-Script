#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if a binary tree is full.
 * @tree: pointer to the root node of the tree to check.
 * Return: If tree is NULL, your function must return 0.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	// If the tree is NULL, it's considered not full
	if (tree == NULL)
		return (0);
	
	// If both left and right children are present, recursively check both subtrees
	if (tree->left != NULL && tree->right != NULL)
		return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));
	
	// If both left and right children are missing, the tree is full
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	
	// If one child is missing but the other is present, the tree is not full
	return (0);
}
