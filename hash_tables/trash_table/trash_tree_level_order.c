#include "trash_table.h"

/**
 * enqueue - add a tree node to a queue
 * @rear: the address of a pointer to the rear of a queue
 * @item: a pointer a tree node to enqueue
 * Return: Return a pointer to the dequeued item.
 *
 * Description: Add an item to the rear of a queue and update the address
 * pointed to by rear. Be aware that rear must not be NULL.
 *
 * Return: If memory allocation fails, return NULL.
 * Otherwise, return a pointer to the new rear.
 */
trash_queue_t *enqueue(trash_queue_t **rear, const trash_node_t *item)
{
	trash_queue_t *temp = malloc(sizeof(*temp));

	if (temp)
	{
		temp->item = item;
		if (*rear)
		{
			temp->next = (*rear)->next;
			(*rear)->next = temp;
		}
		else
		{
			temp->next = temp;
		}
		*rear = temp;
	}
	return (temp);
}


/**
 * dequeue - remove a tree node from a queue
 * @rear: the address of a pointer to the rear of a queue
 *
 * Description: Remove an item from the front of a queue and update the
 * address pointed to rear. Be aware  that the queue must not be empty and
 * rear must not be NULL.
 *
 * Return: Return a pointer to the dequeued item.
 */
const trash_node_t *dequeue(trash_queue_t **rear)
{
	trash_queue_t *front = (*rear)->next;
	const trash_node_t *item = front->item;

	if (*rear == front)
		*rear = NULL;
	else
		(*rear)->next = front->next;
	free(front);
	return (item);
}


/**
 * trash_tree_level_order - apply a function to a binary tree in level-order
 * @root: a pointer to the root node
 * @func: a function that takes a tree node pointer and returns nothing
 */
void trash_tree_level_order(
	const trash_node_t *root, void (*func)(const trash_node_t *))
{
	trash_queue_t *rear = NULL;

	if (root && func && enqueue(&rear, root))
	{
		while (rear)
		{
			func(root);
			root = dequeue(&rear);
			if (root->left)
				enqueue(&rear, root->left);
			if (root->right)
				enqueue(&rear, root->right);
		}
	}
}

