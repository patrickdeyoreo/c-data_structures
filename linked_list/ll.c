// Function definitions for a linked list

#include "ll.h"


// Create an empty list
ll_t *ll_new(ll_node_t *head, size_t size)
{
        ll_t *new_ll = (ll_t *) malloc(sizeof(ll_t));
        new_ll->head = head;
        new_ll->size = size;
        return new_ll;
}



// Create a copy of a list
ll_t *ll_copy(ll_t *src)
{
        ll_t *new_ll = (ll_t *) malloc(sizeof(ll_t));
        new_ll->head = NULL;
        new_ll->size = ll_node_copy_all_to(&new_ll->head, src->head);
        return new_ll;
}



// Append an item to a list
int ll_append(ll_t *list, int to_append)
{
        if (!list)
                return -1;

        _ll_append(&list->head, to_append);
        return ++(list->size);
}

void _ll_append(ll_node_t **head, int to_append)
{
        if (*head)
                _ll_append(&(*head)->next, to_append);
        else
                *head = ll_node_new(to_append, NULL);
        return;
}



// Append a list to a list
int ll_extend(ll_t *list, ll_t *to_append)
{
        if (!list || !to_append || list == to_append)
                return -1;

        _ll_extend(&list->head, to_append->head);
        return list->size += to_append->size;
}

void _ll_extend(ll_node_t **head, ll_node_t *to_append)
{
        if (*head)
                _ll_extend(&(*head)->next, to_append);
        else
                *head = ll_node_copy_all(to_append);
        return;
}



// Insert an item at a given position
int ll_insert(ll_t *list, int index, int to_insert)
{
        if (!list || index < 0 || index >= list->size)
                return -1;

        _ll_insert(&list->head, index, to_insert);
        return ++(list->size);
}

void _ll_insert(ll_node_t **head, int index, int to_insert)
{
        if (index)
                _ll_insert(&(*head)->next, --index, to_insert);
        else
                *head = ll_node_new(to_insert, (*head)->next);
        return;
}



// Remove the first matching item
int ll_remove(ll_t *list, int to_remove)
{
        int removed = 0;

        if (!list)
                return -1;

        removed = _ll_remove(&list->head, to_remove);
        list->size -= removed;
        return removed;
}

int _ll_remove(ll_node_t **head, int to_remove)
{
        ll_node_t *match = NULL;

        if (!*head)
                return 0;

        if ((*head)->data == to_remove) {
                match = *head;
                *head = (*head)->next;
                free(match);
                return 1;
        }

        return _ll_remove(&(*head)->next, to_remove);
}



// Remove and return the item at a given position
int ll_pop(ll_t *list, int index)
{
        int popped = 0;
        if (!list || index < 0 || index >= list->size)
                return -1;

        popped= _ll_pop(&list->head, index);
        --(list->size);
        return popped;
}

int _ll_pop(ll_node_t **head, int index)
{
        ll_node_t *match = NULL;
        int popped = 0;

        if (!*head)
                return 0;
        if (index)
                return _ll_pop(&(*head)->next, --index);

        popped = (*head)->data;

        match = *head;
        *head = (*head)->next;
        free(match);

        return popped;
}



// Remove all items in a list
int ll_clear(ll_t *list)
{
        size_t removed = 0;

        if (!list)
                return -1;

        removed = _ll_clear(&list->head);
        return list->size -= removed;
}

size_t _ll_clear(ll_node_t **head)
{
        size_t removed = 0;

        if (!*head)
                return 0;

        removed = _ll_clear(&(*head)->next);
        free(*head);
        *head = NULL;
        return ++removed;
}



// Return the number of times an item appears in a list
int ll_count(ll_t *list, int to_count)
{
        if (!list)
                return -1;

        return _ll_count(&list->head, to_count);
}

size_t _ll_count(ll_node_t **head, int to_count)
{
        if (!*head)
                return 0;
        return _ll_count(&(*head)->next, to_count) +
                ((*head)->data == to_count);
}



// Reverse a list in place
void ll_reverse(ll_t *list)
{
        if (list)
                _ll_reverse(&list->head, list->head);
        return;
}

ll_node_t *_ll_reverse(ll_node_t **head, ll_node_t *current)
{
        ll_node_t *tail = NULL;

        if (!current)
                return NULL;

        if (tail = _ll_reverse(head, current->next)) {
                current->next = NULL;
                tail->next = current;
        }
        else {
                *head = current;
        }

        return current;
}



// Print all items in a list
void ll_print(ll_t *list)
{
        if (list)
                _ll_print(list->head);
        return;
}

void _ll_print(ll_node_t *head)
{
        if (!head)
                return;
        if (head->next)
                printf("%d, ", head->data);
        else
                printf("%d\n", head->data);

        _ll_print(head->next);

        return;
}
