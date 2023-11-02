#include "binary_trees.h"

/**
 * bal - Measures the balance factor of an AVL tree
 * @tree: tree to go through
 * Return: balanced factor
 */
void bal(avl_t **tree)
{
	int bval;

	if (tree == NULL || *tree == NULL)
		return; // Return if the tree is empty or NULL.
	if ((*tree)->left == NULL && (*tree)->right == NULL)
		return; // Return if the current node is a leaf (no children).

	bal(&(*tree)->left); // Recursively call bal on the left subtree.
	bal(&(*tree)->right); // Recursively call bal on the right subtree.

	// Calculate the balance factor for the current AVL node.
	bval = binary_tree_balance((const binary_tree_t *)*tree);

	if (bval > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree); // If balance factor > 1, perform a right rotation.
	else if (bval < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree); // If balance factor < -1, perform a left rotation.
}

/**
 * successor - Get the next successor, i.e., the minimum node in the right subtree
 * @node: tree to check
 * Return: the minimum value of this tree
 */
int successor(bst_t *node)
{
	int left = 0;

	if (node == NULL)
	{
		return (0); // If the node is NULL, return 0.
	}
	else
	{
		left = successor(node->left); // Recursively find the leftmost node in the left subtree.
		if (left == 0)
		{
			return (node->n); // Return the minimum value when no more left nodes are found.
		}
		return (left);
	}
}

/**
 * remove_type - Function that removes a node depending on its children
 * @root: node to remove
 * Return: 0 if it has no children, or other value if it has children
 */
int remove_type(bst_t *root)
{
	int new_value = 0;

	if (!root->left && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;

		free(root); // If the node has no children, remove it and adjust its parent's reference.
		return (0);
	}
	else if ((!root->left && root->right) || (!root->right && root->left))
	{
		if (!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;
			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;
			root->left->parent = root->parent;
		}

		free(root); // If the node has one child, remove it and adjust its parent's reference.
		return (0);
	}
	else
	{
		new_value = successor(root->right); // Find the successor node (minimum value) in the right subtree.
		root->n = new_value; // Replace the current node's value with the successor value.
		return (new_value);
	}
}

/**
 * bst_remove - Remove a node from a BST tree
 * @root: root of the tree
 * @value: node with this value to remove
 * Return: the tree changed
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int type = 0;

	if (root == NULL)
		return (NULL); // Return NULL if the tree is empty.

	if (value < root->n)
		bst_remove(root->left, value); // Recursively search for the node to remove in the left subtree.
	else if (value > root->n)
		bst_remove(root->right, value); // Recursively search for the node to remove in the right subtree.
	else if (value == root->n)
	{
		type = remove_type(root); // Call remove_type to handle different cases for node removal.
		if (type != 0)
			bst_remove(root->right, type); // If there's a successor, continue removing it from the right subtree.
	}
	else
		return (NULL); // Return NULL if the value is not found.

	return (root); // Return the modified BST tree.
}

/**
 * avl_remove - Remove a node from an AVL tree
 * @root: root of the tree
 * @value: node with this value to remove
 * Return: the tree changed
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *root_a = (avl_t *)bst_remove((bst_t *)root, value); // Call bst_remove to remove the node.

	if (root_a == NULL)
		return (NULL);

	// Perform AVL tree balancing.
	bal(&root_a);

	return (root_a); // Return the modified AVL tree.
}
