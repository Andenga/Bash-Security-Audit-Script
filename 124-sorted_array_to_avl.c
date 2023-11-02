#include "binary_trees.h"

/**
 * aux_sort - create the tree using the half element of the array
 * @parent: parent of the node to create
 * @array: sorted array
 * @begin: position where the array starts
 * @last: position where the array ends
 * Return: tree created
 */
avl_t *aux_sort(avl_t *parent, int *array, int begin, int last)
{
	avl_t *root;
	binary_tree_t *aux;
	int mid = 0;

	if (begin <= last)
	{
		mid = (begin + last) / 2; // Calculate the middle index of the array.
		aux = binary_tree_node((binary_tree_t *)parent, array[mid]); // Create a new node with the middle element.
		if (aux == NULL)
			return (NULL); // Return NULL if memory allocation fails.
		root = (avl_t *)aux;
		root->left = aux_sort(root, array, begin, mid - 1); // Recursively create the left subtree.
		root->right = aux_sort(root, array, mid + 1, last); // Recursively create the right subtree.
		return (root); // Return the root of the AVL tree.
	}
	return (NULL); // Return NULL when the start position is greater than the end position.
}

/**
 * sorted_array_to_avl - create an AVL tree from a sorted array
 * @array: sorted array
 * @size: size of the sorted array
 * Return: AVL tree from the sorted array
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL); // Return NULL if the input array is empty or NULL.

	// Call the auxiliary function to build the AVL tree with the sorted array.
	return aux_sort(NULL, array, 0, ((int)(size)) - 1);
}
