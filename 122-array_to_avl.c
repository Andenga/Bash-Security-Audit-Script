#include "binary_trees.h"

/**
 * array_to_avl - Builds an AVL tree from an array.
 * @array: A pointer to the first element of the array to be converted.
 * @size: The number of elements in @array.
 *
 * Return: A pointer to the root node of the created AVL, or NULL upon failure.
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL; // Initialize the AVL tree to be built.
	size_t i, j;

	if (array == NULL)
		return (NULL); // Return NULL if the input array is empty or NULL.

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < i; j++)
		{
			if (array[j] == array[i])
				break; // Check for duplicate values in the array.
		}
		if (j == i)
		{
			// If no duplicate is found, insert the unique value into the AVL tree.
			if (avl_insert(&tree, array[i]) == NULL)
				return (NULL); // Return NULL if insertion fails.
		}
	}

	return (tree); // Return a pointer to the root of the created AVL tree.
}
