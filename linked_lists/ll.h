// Structures and function prototypes for a linked list

#ifndef LL_H
#define LL_H

#include "ll_node.h"
#include <stdio.h>


// Linked list structure
typedef struct ll {
        ll_node_t *head;
        size_t size;
} ll_t;


// Create an empty list
ll_t *ll_new(void);

// Create a copy of a list
ll_t *ll_copy(ll_t *src);


// Append an item to a list
int ll_append(ll_t *list, int to_append);
void _ll_append(ll_node_t **head, int to_append);


// Append a list to a list
int ll_extend(ll_t *list, ll_t *to_append);
void _ll_extend(ll_node_t **head, ll_node_t *to_append);


// Insert an item at a given position
int ll_insert(ll_t *list, int index, int to_insert);
void _ll_insert(ll_node_t **head, int index, int to_insert);


// Remove the first matching item
int ll_remove(ll_t *list, int to_remove);
int _ll_remove(ll_node_t **head, int to_remove);


// Remove and return the item at a given position
int ll_pop(ll_t *list, int index);
int _ll_pop(ll_node_t **head, int index);


// Remove all items in a list
int ll_clear(ll_t *list);
size_t _ll_clear(ll_node_t **head);


// Return the number of times an item appears in a list
int ll_count(ll_t *list, int to_count);
size_t _ll_count(ll_node_t **head, int to_count);


// Reverse a list in place
void ll_reverse(ll_t *list);
ll_node_t *_ll_reverse(ll_node_t **head, ll_node_t *current);


// Print all items in a list
void ll_print(ll_t *list);
void _ll_print(ll_node_t *head);


#endif /* LL_H */
