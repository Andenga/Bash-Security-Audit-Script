#include "binary_trees.h"

/**
 * create_node - Creates a new levelorder_queue_t node.
 * @node: The binary tree node for the new node to contain.
 *
 * Return: If an error occurs, NULL.
 *         Otherwise, a pointer to the new node.
 */
levelorder_queue_t *create_node(binary_tree_t *node)
{
    levelorder_queue_t *new;

    // Allocate memory for a new levelorder_queue_t node
    new = malloc(sizeof(levelorder_queue_t));
    if (new == NULL)
        return (NULL);

    // Initialize the new node with the given binary tree node and a NULL next pointer
    new->node = node;
    new->next = NULL;

    return (new);
}

/**
 * free_queue - Frees a levelorder_queue_t queue.
 * @head: A pointer to the head of the queue.
 */
void free_queue(levelorder_queue_t *head)
{
    levelorder_queue_t *tmp;

    while (head != NULL)
    {
        // Store the next node in the temporary variable
        tmp = head->next;

        // Free the current node
        free(head);

        // Move to the next node in the queue
        head = tmp;
    }
}

/**
 * push - Pushes a node to the back of a levelorder_queue_t queue.
 * @node: The binary tree node to print and push.
 * @head: A double pointer to the head of the queue.
 * @tail: A double pointer to the tail of the queue.
 *
 * Description: Upon malloc failure, exits with a status code of 1.
 */
void push(binary_tree_t *node, levelorder_queue_t *head,
        levelorder_queue_t **tail)
{
    levelorder_queue_t *new;

    // Create a new levelorder_queue_t node with the given binary tree node
    new = create_node(node);
    if (new == NULL)
    {
        // If malloc fails, free the queue and exit with a status code of 1
        free_queue(head);
        exit(1);
    }

    // Update the next pointer of the current tail node to point to the new node
    (*tail)->next = new;

    // Update the tail to the new node
    *tail = new;
}

/**
 * pop - Pops the head of a levelorder_queue_t queue.
 * @head: A double pointer to the head of the queue.
 */
void pop(levelorder_queue_t **head)
{
    levelorder_queue_t *tmp;

    // Store the next node in the temporary variable
    tmp = (*head)->next;

    // Free the current head node
    free(*head);

    // Update the head to the next node in the queue
    *head = tmp;
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: A pointer to the root node of the tree to traverse.
 *
 * Return: If the tree is NULL or not complete, 0.
 *         Otherwise, 1.
 *
 * Description: Upon malloc failure, exits with a status code of 1.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
    levelorder_queue_t *head, *tail;
    unsigned char flag = 0;

    // If the input tree is NULL, it's not complete, so return 0
    if (tree == NULL)
        return (0);

    // Initialize the head and tail of the queue with the root node
    head = tail = create_node((binary_tree_t *)tree);

    // If malloc fails, exit with a status code of 1
    if (head == NULL)
        exit(1);

    // Traverse the tree level by level
    while (head != NULL)
    {
        if (head->node->left != NULL)
        {
            if (flag == 1)
            {
                // If we encounter a NULL node after encountering non-NULL nodes, it's not complete
                free_queue(head);
                return (0);
            }
            // Push the left child node to the queue
            push(head->node->left, head, &tail);
        }
        else
            flag = 1;
        if (head->node->right != NULL)
        {
            if (flag == 1)
            {
                // If we encounter a NULL node after encountering non-NULL nodes, it's not complete
                free_queue(head);
                return (0);
            }
            // Push the right child node to the queue
            push(head->node->right, head, &tail);
        }
        else
            flag = 1;

        // Pop the current head node as we process it
        pop(&head);
    }

    // If all levels are traversed without breaking the completeness rule, return 1
    return (1);
}
