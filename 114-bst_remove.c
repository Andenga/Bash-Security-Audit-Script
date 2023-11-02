#include "binary_trees.h"

/**
 * inorder_successor - Returns the minimum value of a binary search tree.
 * @root: A pointer to the root node of the BST to search.
 *
 * Return: The minimum value in @tree.
 */
bst_t *inorder_successor(bst_t *root)
{
    // Traverse left until you reach the leftmost node (minimum value).
    while (root->left != NULL)
        root = root->left;
    // Return the leftmost node, which is the minimum value.
    return (root);
}

/**
 * bst_delete - Deletes a node from a binary search tree.
 * @root: A pointer to the root node of the BST.
 * @node: A pointer to the node to delete from the BST.
 *
 * Return: A pointer to the new root node after deletion.
 */
bst_t *bst_delete(bst_t *root, bst_t *node)
{
    bst_t *parent = node->parent, *successor = NULL;

    // Case 1: No children or right-child only
    if (node->left == NULL)
    {
        if (parent != NULL && parent->left == node)
            parent->left = node->right;
        else if (parent != NULL)
            parent->right = node->right;
        if (node->right != NULL)
            node->right->parent = parent;
        // Free the node and return the new root.
        free(node);
        return (parent == NULL ? node->right : root);
    }

    // Case 2: Left-child only
    if (node->right == NULL)
    {
        if (parent != NULL && parent->left == node)
            parent->left = node->left;
        else if (parent != NULL)
            parent->right = node->left;
        if (node->left != NULL)
            node->left->parent = parent;
        // Free the node and return the new root.
        free(node);
        return (parent == NULL ? node->left : root);
    }

    // Case 3: Two children
    successor = inorder_successor(node->right);
    // Copy the value of the in-order successor to the current node.
    node->n = successor->n;

    // Delete the in-order successor from the right subtree.
    return (bst_delete(root, successor));
}

/**
 * bst_remove_recursive - Removes a node from a binary search tree recursively.
 * @root: A pointer to the root node of the BST to remove a node from.
 * @node: A pointer to the current node in the BST.
 * @value: The value to remove from the BST.
 *
 * Return: A pointer to the root node after deletion.
 */
bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value)
{
    if (node != NULL)
    {
        if (node->n == value)
            return bst_delete(root, node);
        if (node->n > value)
            return bst_remove_recursive(root, node->left, value);
        return bst_remove_recursive(root, node->right, value);
    }
    return NULL;
}

/**
 * bst_remove - Removes a node from a binary search tree.
 * @root: A pointer to the root node of the BST to remove a node from.
 * @value: The value to remove in the BST.
 *
 * Return: A pointer to the new root node after deletion.
 *
 * Description: If the node to be deleted has two children, it
 *              is replaced with its first in-order successor.
 */
bst_t *bst_remove(bst_t *root, int value)
{
    return bst_remove_recursive(root, root, value);
}
