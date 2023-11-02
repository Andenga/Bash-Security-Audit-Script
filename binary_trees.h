#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
    int n;  // Integer value stored in the node
    struct binary_tree_s *parent; // Pointer to the parent node
    struct binary_tree_s *left;   // Pointer to the left child node
    struct binary_tree_s *right;  // Pointer to the right child node
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s bst_t;
typedef struct binary_tree_s avl_t;
typedef struct binary_tree_s heap_t;

/**
 * struct levelorder_queue_s - Level order traversal queue.
 * @node: A node of a binary tree.
 * @next: The next node to traverse to in the binary tree.
 */
typedef struct levelorder_queue_s
{
    binary_tree_t *node; // A node of a binary tree
    struct levelorder_queue_s *next; // The next node to traverse in the binary tree
} levelorder_queue_t;

/* Printing helper function */
void binary_tree_print(const binary_tree_t *);

// Function prototypes for various binary tree operations
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);  // Create a new binary tree node
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);  // Insert a left child node
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);  // Insert a right child node
void binary_tree_delete(binary_tree_tree_t *tree);  // Delete an entire binary tree
int binary_tree_is_leaf(const binary_tree_t *node);  // Check if a node is a leaf node
int binary_tree_is_root(const binary_tree_t *node);  // Check if a node is the root of the tree
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));  // Perform preorder traversal
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));  // Perform inorder traversal
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));  // Perform postorder traversal
size_t binary_tree_height(const binary_tree_t *tree);  // Get the height of the tree
size_t binary_tree_depth(const binary_tree_t *tree);  // Get the depth of a node
size_t binary_tree_size(const binary_tree_t *tree);  // Get the size of the tree
size_t binary_tree_leaves(const binary_tree_t *tree);  // Get the number of leaf nodes
size_t binary_tree_nodes(const binary_tree_t *tree);  // Get the number of non-leaf nodes
int binary_tree_balance(const binary_tree_t *tree);  // Check if the tree is balanced
int binary_tree_is_full(const binary_tree_t *tree);  // Check if the tree is a full binary tree
int binary_tree_is_perfect(const binary_tree_t *tree);  // Check if the tree is a perfect binary tree
binary_tree_t *binary_tree_sibling(binary_tree_t *node);  // Get the sibling of a node
binary_tree_t *binary_tree_uncle(binary_tree_t *node);  // Get the uncle of a node
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second);  // Find the common ancestor of two nodes
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));  // Perform level order traversal
int binary_tree_is_complete(const binary_tree_t *tree);  // Check if the tree is a complete binary tree
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree);  // Rotate a tree to the left
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree);  // Rotate a tree to the right
int binary_tree_is_bst(const binary_tree_t *tree);  // Check if the tree is a binary search tree
bst_t *bst_insert(bst_t **tree, int value);  // Insert a value into a binary search tree
bst_t *array_to_bst(int *array, size_t size);  // Convert an array to a binary search tree
bst_t *bst_search(const bst_t *tree, int value);  // Search for a value in a binary search tree
bst_t *bst_remove(bst_t *root, int value);  // Remove a value from a binary search tree
int binary_tree_is_avl(const binary_tree_t *tree);  // Check if the tree is an AVL tree
avl_t *avl_insert(avl_t **tree, int value);  // Insert a value into an AVL tree
avl_t *array_to_avl(int *array, size_t size);  // Convert an array to an AVL tree
avl_t *avl_remove(avl_t *root, int value);  // Remove a value from an AVL tree
avl_t *sorted_array_to_avl(int *array, size_t size);  // Convert a sorted array to an AVL tree
int binary_tree_is_heap(const binary_tree_t *tree);  // Check if the tree is a binary heap
heap_t *heap_insert(heap_t **root, int value);  // Insert a value into a binary heap
heap_t *array_to_heap(int *array, size_t size);  // Convert an array to a binary heap
int heap_extract(heap_t **root);  // Extract the root value from a binary heap
int *heap_to_sorted_array(heap_t *heap, size_t *size);  // Convert a binary heap to a sorted array

#endif /* BINARY_TREES_H */
