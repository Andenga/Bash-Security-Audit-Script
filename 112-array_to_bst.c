#include "binary_trees.h"

/**
 * array_to_bst - Builds a Binary Search Tree (BST) from an array.
 * @array: Pointer to the first element of the array to be converted into a BST.
 * @size: Number of elements in the array.
 *
 * Return: A pointer to the root node of the created BST, or NULL on failure.
 */
bst_t *array_to_bst(int *array, size_t size)
{
    bst_t *tree;
    size_t index;

    if (array == NULL)
        return (NULL);  // If the input array is NULL, return NULL.

    tree = NULL;  // Initialize the BST as an empty tree.
    
    for (index = 0; index < size; index++)
    {
        bst_insert(&tree, array[index]);  // Insert each element from the array into the BST.
    }
    
    return (tree);  // Return a pointer to the root node of the created BST.
}
