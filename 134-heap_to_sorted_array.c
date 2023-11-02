#include "binary_trees.h"

/**
 * count_h_nodes - Counts the number of nodes inside a tree
 * @root: Pointer to tree's root node
 *
 * Return: Number of tree nodes
 */
int count_h_nodes(binary_tree_t *root)
{
	if (!root)
		return (0);

	// Recursively count nodes in the left and right subtrees
	return (1 + count_h_nodes(root->left) +
		    count_h_nodes(root->right));
}

/**
 * heap_to_sorted_array - Creates a sorted array from a max heap
 * @heap: Pointer to heap's node
 * @size: Pointer to arrays size
 *
 * Return: Pointer to an array of integers
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int i, nodes, *arr = NULL;

	*size = 0;
	if (!heap)
		return (NULL);

	nodes = count_h_nodes(heap); // Calculate the number of nodes in the heap
	arr = malloc(sizeof(*arr) * nodes); // Allocate memory for the sorted array
	if (!arr)
		return (NULL);

	*size = nodes; // Set the size of the sorted array
	for (i = 0; i < nodes; i++)
		arr[i] = heap_extract(&heap); // Extract the max element from the heap and store it in the array

	return (arr); // Return the sorted array
}
