#include "binary_trees.h"

/**
 * count_h_nodes - Counts the number of nodes in a binary tree.
 * @root: Pointer to the root node of the tree.
 *
 * Return: The number of nodes in the tree.
 */
int count_h_nodes(binary_tree_t *root)
{
    // Check if the root node is NULL (base case)
    if (!root)
        return (0);

    // Recursively count nodes in the left and right subtrees and add 1 for the current node
    return (1 + count_h_nodes(root->left) + count_h_nodes(root->right);
}

/**
 * heap_to_sorted_array - Converts a max heap into a sorted integer array.
 * @heap: Pointer to the root node of the max heap.
 * @size: Pointer to store the size of the resulting array.
 *
 * Return: A pointer to an array of integers containing the sorted values.
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
    int i, nodes, *arr = NULL;

    // Initialize the size of the array to 0.
    *size = 0;

    // Check if the heap is NULL.
    if (!heap)
        return (NULL);

    // Count the number of nodes in the max heap.
    nodes = count_h_nodes(heap);

    // Allocate memory for the array to store sorted values.
    arr = malloc(sizeof(*arr) * nodes);
    if (!arr)
        return (NULL);

    // Set the size to the number of nodes.
    *size = nodes;

    // Extract values from the max heap into the array while maintaining the sorted order.
    for (i = 0; i < nodes; i++)
        arr[i] = heap_extract(&heap);

    return (arr);
}
