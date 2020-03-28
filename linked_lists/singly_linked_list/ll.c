/* Function definitions for a linked list of integers */

#include "ll.h"
#include <stdio.h>


/* Create an empty list */
ll_t ll_new(void)
{
	ll_t new_ll = { NULL, 0 };

	return (new_ll);
}



/* Copy items to a list from another list */
ll_t *ll_copy(ll_t *dest, ll_t src)
{
	if (dest)
		dest->size = ll_node_copy_all_to(&dest->head, src.head);

	return (dest);
}



/* Append an item to a list */
int ll_append(ll_t *list, int to_append)
{
	if (!list)
		return (-1);

	_ll_append(&list->head, to_append);

	list->size += 1;

	return (list->size);
}

void _ll_append(ll_node_t **head, int to_append)
{
	if (*head)
		_ll_append(&(*head)->next, to_append);
	else
		*head = ll_node_new(to_append, NULL);
}



/* Append items to a list from another list */
int ll_extend(ll_t *list, ll_t to_append)
{
	if (!list || !_ll_extend(&list->head, to_append.head))
		return (-1);

	list->size += to_append.size;

	return (to_append.size);
}

int _ll_extend(ll_node_t **head, ll_node_t *to_append)
{
	if (*head)
	{
		if (*head == to_append)
			return (0);
		return (_ll_extend(&(*head)->next, to_append));
	}

	*head = ll_node_copy_all(to_append);

	return (1);
}



/* Insert an item in a list at the specified index */
int ll_insert(ll_t *list, int index, int to_insert)
{
	if (index < 0)
		index += list->size + 1;
	if (!list || index < 0 || index > list->size)
		return (-1);

	_ll_insert(&list->head, index, to_insert);

	list->size += 1;

	return (list->size);
}

void _ll_insert(ll_node_t **head, int index, int to_insert)
{
	if (index)
		_ll_insert(&(*head)->next, --index, to_insert);
	else
		*head = ll_node_new(to_insert, *head);
}



/* Remove the first matching item from a list */
int ll_remove(ll_t *list, int to_remove)
{
	int removed = 0;

	if (!list)
		return (-1);

	removed = _ll_remove(&list->head, to_remove);

	list->size -= removed;

	return (removed);
}

int _ll_remove(ll_node_t **head, int to_remove)
{
	ll_node_t *match = NULL;

	if (!*head)
		return (0);

	if ((*head)->data == to_remove)
	{
		match = *head;
		*head = (*head)->next;
		free(match);
		return (1);
	}

	return (_ll_remove(&(*head)->next, to_remove));
}



/* Get and remove an item from a list at the specified index */
int ll_pop(ll_t *list, int index)
{
	int popped;

	if (index < 0)
		index += list->size;

	if (!list || index < 0 || index >= list->size)
		return (-1);

	popped = _ll_pop(&list->head, index);

	list->size += 1;

	return (popped);
}

int _ll_pop(ll_node_t **head, int index)
{
	int popped = 0;
	ll_node_t *match = NULL;

	if (!*head)
		return (0);
	if (index)
		return (_ll_pop(&(*head)->next, index - 1));

	popped = (*head)->data;

	match = *head;
	*head = (*head)->next;
	free(match);

	return (popped);
}



/* Remove all items from a list */
int ll_clear(ll_t *list)
{
	int removed = 0;

	if (!list)
		return (-1);

	removed = _ll_clear(&list->head);

	list->size -= removed;

	return (list->size);
}

int _ll_clear(ll_node_t **head)
{
	int removed = 0;

	if (!*head)
		return (0);

	removed = _ll_clear(&(*head)->next);

	free(*head);
	*head = NULL;

	return (removed + 1);
}



/* Count the number of times an item appears in a list */
int ll_count(ll_t list, int to_count)
{
	return (_ll_count(&list.head, to_count));
}

int _ll_count(ll_node_t **head, int to_count)
{
	if (!*head)
		return (0);

	return (_ll_count(&(*head)->next, to_count) +
			(to_count == (*head)->data));
}



/* Reverse the items in a list */
ll_t *ll_reverse(ll_t *list)
{
	if (list && list->head)
		_ll_reverse(&list->head, list->head);

	return (list);
}

ll_node_t **_ll_reverse(ll_node_t **head, ll_node_t *current)
{
	if (current->next)
	{
		head = _ll_reverse(head, current->next);
		current->next = NULL;
	}
	*head = current;
	return (&current->next);
}



/* Print all items in a list */
void ll_print(ll_t list)
{
	_ll_print(list.head);
}

void _ll_print(ll_node_t *head)
{
	if (head)
	{
		printf("%d", head->data);

		if (head->next)
			printf(", ");

		_ll_print(head->next);
	}
	else
	{
		putchar('\n');
	}
}
