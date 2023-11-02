#include "binary_trees.h"

/**
 * bal - Rebalances an AVL tree node after an insert operation.
 * @tree: Pointer to an AVL tree node.
 */
void bal(avl_t **tree)
{
    int bval;

    if (tree == NULL || *tree == NULL)
        return;
    
    if ((*tree)->left == NULL && (*tree)->right == NULL)
        return;

    bal(&(*tree)->left);
    bal(&(*tree)->right);

    bval = binary_tree_balance((const binary_tree_t *)*tree);

    if (bval > 1)
        *tree = binary_tree_rotate_right((binary_tree_t *)*tree);
    else if (bval < -1)
        *tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}

/**
 * successor - Finds the minimum value node in the right subtree.
 * @node: Pointer to the tree node to search.
 * Return: The minimum value in the tree node.
 */
int successor(bst_t *node)
{
    int left = 0;

    if (node == NULL)
    {
        return (0);
    }
    else
    {
        left = successor(node->left);
        if (left == 0)
        {
            return (node->n);
        }
        return (left);
    }
}

/**
 * remove_type - Removes a node from a binary search tree based on its children.
 * @root: Node to remove.
 * Return: 0 if it has no children, or a different value if it has children.
 */
int remove_type(bst_t *root)
{
    int new_value = 0;

    if (!root->left && !root->right)
    {
        if (root->parent->right == root)
            root->parent->right = NULL;
        else
            root->parent->left = NULL;
        free(root);
        return (0);
    }
    else if ((!root->left && root->right) || (!root->right && root->left))
    {
        if (!root->left)
        {
            if (root->parent->right == root)
                root->parent->right = root->right;
            else
                root->parent->left = root->right;
            root->right->parent = root->parent;
        }
        if (!root->right)
        {
            if (root->parent->right == root)
                root->parent->right = root->left;
            else
                root->parent->left = root->left;
            root->left->parent = root->parent;
        }
        free(root);
        return (0);
    }
    else
    {
        new_value = successor(root->right);
        root->n = new_value;
        return (new_value);
    }
}

/**
 * bst_remove - Removes a node from a binary search tree (BST).
 * @root: The root of the BST.
 * @value: The value of the node to remove.
 * Return: The updated BST.
 */
bst_t *bst_remove(bst_t *root, int value)
{
    int type = 0;

    if (root == NULL)
        return (NULL);

    if (value < root->n)
        bst_remove(root->left, value);
    else if (value > root->n)
        bst_remove(root->right, value);
    else if (value == root->n)
    {
        type = remove_type(root);
        if (type != 0)
            bst_remove(root->right, type);
    }
    else
        return (NULL);

    return (root);
}

/**
 * avl_remove - Removes a node from an AVL tree.
 * @root: The root of the AVL tree.
 * @value: The value of the node to remove.
 * Return: The updated AVL tree.
 */
avl_t *avl_remove(avl_t *root, int value)
{
    avl_t *root_a = (avl_t *)bst_remove((bst_t *)root, value);

    if (root_a == NULL)
        return (NULL);

    bal(&root_a);
    return (root_a);
}
