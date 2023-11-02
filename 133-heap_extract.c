#include "binary_trees.h"

/**
 * count_heap_nodes - Counts the number of nodes inside a binary tree.
 * @root: Pointer to the root node of the tree.
 *
 * Return: The number of nodes in the tree.
 */
int count_heap_nodes(binary_tree_t *root)
{
    // Check if the root node is NULL (base case)
    if (!root)
        return (0);

    // Recursively count nodes in the left and right subtrees and add 1 for the current node
    return (1 + count_heap_nodes(root->left) +
            count_heap_nodes(root->right));
}

/**
 * bubble_down - Moves a node value to its correct position in a max heap.
 * @parent: Pointer to a node in the max heap.
 */
void bubble_down(heap_t *parent)
{
    int temp;
    heap_t *max_child = NULL;

    // Check if the parent node is NULL
    if (!parent)
        return;

    while (parent && parent->left)
    {
        max_child = parent->left;

        // Determine the maximum child (either left or right)
        if (parent->right && parent->right->n > parent->left->n)
            max_child = parent->right;

        // Swap values if the maximum child is greater than the parent
        if (max_child->n > parent->n)
        {
            temp = parent->n;
            parent->n = max_child->n;
            max_child->n = temp;
        }

        parent = max_child;
    }
}

/**
 * get_parent - Finds the parent node for a certain node in a max heap.
 * @root: Pointer to the root of the max heap.
 * @index: Index of the current node being searched.
 * @pind: Index to be found.
 *
 * Return: Pointer to the parent node.
 */
heap_t *get_parent(heap_t *root, int index, int pind)
{
    heap_t *left = NULL, *right = NULL;

    // Check if the root node is NULL or if the index exceeds the target index
    if (!root || index > pind)
        return (NULL);

    // If the target index is reached, return the root node
    if (index == pind)
        return (root);

    // Recursively search for the parent in the left and right subtrees
    left = get_parent(root->left, index * 2 + 1, pind);
    if (left)
        return (left);

    right = get_parent(root->right, index * 2 + 2, pind);
    if (right)
        return (right);

    return (NULL);
}

/**
 * remove_last_node - Removes the last node in a max heap.
 * @root: Double pointer to the root node of the max heap.
 * @parent: Pointer to the parent node from which to remove the last node.
 */
void remove_last_node(heap_t **root, heap_t *parent)
{
    // Check if the parent is the root and has no left child (base case)
    if (parent == *root && !parent->left)
    {
        free(*root);
        *root = NULL;
        return;
    }

    // If the parent has a right child, replace the root node with the right child's value and free it
    if (parent->right)
    {
        (*root)->n = parent->right->n;
        free(parent->right);
        parent->right = NULL;
    }
    // If the parent has no right child, replace the root node with the left child's value and free it
    else if (parent->left)
    {
        (*root)->n = parent->left->n;
        free(parent->left);
        parent->left = NULL;
    }

    // Adjust the max heap structure by performing a "bubble down" operation
    bubble_down(*root);
}

/**
 * heap_extract - Extracts the maximum value from a max heap.
 * @root: Double pointer to the root node of the max heap.
 *
 * Return: The maximum value in the max heap.
 */
int heap_extract(heap_t **root)
{
    int nodes, pind = 0, max_val = 0;
    heap_t *parent;

    // Check if the root or the double pointer to the root is NULL
    if (!root || !(*root))
        return (0);

    // Store the maximum value (root's value) to be returned
    max_val = (*root)->n;

    // Calculate the number of nodes in the max heap
    nodes = count_heap_nodes(*root);

    // Calculate the index of the parent node for the last node
    pind = (nodes - 2) / 2;

    // Find the parent of the last node
    parent = get_parent(*root, 0, pind);

    // Remove the last node and adjust the max heap structure
    remove_last_node(root, parent);

    return (max_val);
}
