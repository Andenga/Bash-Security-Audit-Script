#include "binary_trees.h"

/**
 * height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL, your function must return 0, else return height.
 */
size_t height(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		size_t l = 0, r = 0;

		l = tree->left ? 1 + binary_tree_height(tree->left) : 1; // Calculate the height of the left subtree.
		r = tree->right ? 1 + binary_tree_height(tree->right) : 1; // Calculate the height of the right subtree.
		return ((l > r) ? l : r); // Return the maximum height of the left and right subtrees.
	}
	return (0); // Return 0 if the tree is NULL.
}

/**
 * balance - Measures the balance factor of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the balance factor.
 *
 * Return: If tree is NULL, return 0, else return balance factor.
 */
int balance(const binary_tree_t *tree)
{
	return (tree != NULL ? height(tree->left) - height(tree->right) : 0); // Calculate and return the balance factor of the tree.
}

/**
 * avl_insert_recursive - Inserts a value into an AVL tree recursively.
 * @tree: A double pointer to the root node of the AVL tree to insert into.
 * @parent: The parent node of the current working node.
 * @new: A double pointer to store the new node.
 * @value: The value to insert into the AVL tree.
 *
 * Return: A pointer to the new root after insertion, or NULL on failure.
 */
avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent,
		avl_t **new, int value)
{
	int bfactor;

	if (*tree == NULL)
		return (*new = binary_tree_node(parent, value)); // Create a new node if the current node is NULL.

	if ((*tree)->n > value)
	{
		(*tree)->left = avl_insert_recursive(&(*tree)->left, *tree, new, value); // Recursively insert into the left subtree.
		if ((*tree)->left == NULL)
			return (NULL); // Return NULL on failure.
	}
	else if ((*tree)->n < value)
	{
		(*tree)->right = avl_insert_recursive(&(*tree)->right, *tree, new, value); // Recursively insert into the right subtree.
		if ((*tree)->right == NULL)
			return (NULL); // Return NULL on failure.
	}
	else
		return (*tree); // Return the current node if the value is already present in the tree.

	bfactor = balance(*tree); // Calculate the balance factor of the current node.
	if (bfactor > 1 && (*tree)->left->n > value)
		*tree = binary_tree_rotate_right(*tree); // Perform a right rotation if balance factor > 1 and left child's value > new value.
	else if (bfactor < -1 && (*tree)->right->n < value)
		*tree = binary_tree_rotate_left(*tree); // Perform a left rotation if balance factor < -1 and right child's value < new value.
	else if (bfactor > 1 && (*tree)->left->n < value)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left); // Perform a left rotation on the left child.
		*tree = binary_tree_rotate_right(*tree); // Perform a right rotation on the current node.
	}
	else if (bfactor < -1 && (*tree)->right->n > value)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right); // Perform a right rotation on the right child.
		*tree = binary_tree_rotate_left(*tree); // Perform a left rotation on the current node.
	}

	return (*tree); // Return the modified AVL tree.
}

/**
 * avl_insert - Inserts a value into an AVL tree.
 * @tree: A double pointer to the root node of the AVL tree to insert into.
 * @value: The value to insert into the AVL tree.
 *
 * Return: A pointer to the inserted node, or NULL on failure.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new = NULL;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value); // Create a new root node if the tree is empty.
		return (*tree);
	}
	avl_insert_recursive(tree, *tree, &new, value); // Call the recursive insertion function.
	return (new); // Return the inserted node.
}
