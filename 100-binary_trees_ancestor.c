#include "binary_trees.h"

/**
 * binary_tree_depth - Measures the depth of a node in a binary tree.
 * @tree: A pointer to the node to measure the depth.
 *
 * Return: If tree is NULL, the function must return 0. Otherwise, the depth.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);
    else
        return (1 + binary_tree_depth(tree->parent));
}

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
 * @first: The first node.
 * @second: The second node.
 *
 * Return: The lowest common ancestor of the two nodes.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
                                     const binary_tree_t *second)
{
    size_t height_f = 0, height_s = 0;
    const binary_tree_t *aux = NULL;

    // Calculate the depth (height) of both nodes in the tree
    height_f = binary_tree_depth(first);
    height_s = binary_tree_depth(second);

    if (height_f && height_s)
    {
        if (height_f > height_s)
        {
            // Swap the nodes if necessary so that 'first' is deeper
            aux = first;
            first = second;
            second = aux;
        }

        // Move both nodes up the tree until they have the same ancestor
        while (first)
        {
            aux = second;
            while (aux)
            {
                if (first == aux)
                    return ((binary_tree_t *)first);
                aux = aux->parent;
            }
            first = first->parent;
        }
    }
    else
    {
        // If either node is missing, there's no common ancestor
        return (NULL);
    }

    // If no common ancestor is found, return NULL
    return (NULL);
}
