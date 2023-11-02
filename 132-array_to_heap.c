#include "binary_trees.h"

/**
 * array_to_heap - builds a Max Binary Heap tree
 *
 * @array: pointer to the first element of the array
 * @size: number of elements in the array
 * Return: pointer to the root node of the Max Binary Heap tree
 */
heap_t *array_to_heap(int *array, size_t size)
{
	heap_t *tree;
	size_t i;

	tree = NULL; // Initialize the Max Binary Heap tree as empty

	for (i = 0; i < size; i++)
	{
		heap_insert(&tree, array[i]); // Insert each element from the array into the Max Binary Heap
	}

	return (tree); // Return a pointer to the root node of the Max Binary Heap tree
}
