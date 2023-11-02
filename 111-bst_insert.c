#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree (BST).
 * @tree: Double pointer to the root node of the BST to insert the value.
 * @value: Value to store in the node to be inserted.
 *
 * Return: A pointer to the newly inserted node, or NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
    bst_t *aux = NULL;

    if (tree == NULL)
        return (NULL);  // If the input tree is NULL, return NULL.

    if (*tree == NULL)
    {
        *tree = binary_tree_node(NULL, value);
        return (*tree);  // If the tree is empty, create the root node with the given value and return it.
    }

    aux = *tree;  // Set 'aux' to the current node.

    if (value < aux->n)
    {
        if (aux->left == NULL)
        {
            aux->left = binary_tree_node(aux, value);
            return (aux->left);  // If the value is less than the current node's value and the left child is empty, create a new node on the left and return it.
        }
        return (bst_insert(&(aux->left), value);  // Recursively insert the value into the left subtree.
    }
    else if (value > aux->n)
    {
        if (aux->right == NULL)
        {
            aux->right = binary_tree_node(aux, value);
            return (aux->right);  // If the value is greater than the current node's value and the right child is empty, create a new node on the right and return it.
        }
        return (bst_insert(&(aux->right), value);  // Recursively insert the value into the right subtree.
    }

    return (NULL);  // If the value already exists in the BST, return NULL.
}
