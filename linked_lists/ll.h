/* Structures and function prototypes for a linked list of integers */

#ifndef LL_H
#define LL_H


#include "ll_node.h"


/* Linked list structure */
typedef struct ll {
        ll_node_t *head;
        int size;
} ll_t;


/* Create an empty list */
ll_t ll_new(void);


/* Copy items to a list from another list */
ll_t *ll_copy(ll_t *dest, ll_t src);


/* Append an item to a list */
int ll_append(ll_t *list, int to_append);
void _ll_append(ll_node_t **head, int to_append);


/* Append items to a list from another list */
int ll_extend(ll_t *list, ll_t to_append);
int _ll_extend(ll_node_t **head, ll_node_t *to_append);


/* Insert an item in a list at the specified index */
int ll_insert(ll_t *list, int index, int to_insert);
void _ll_insert(ll_node_t **head, int index, int to_insert);


/* Remove the first matching item from a list */
int ll_remove(ll_t *list, int to_remove);
int _ll_remove(ll_node_t **head, int to_remove);


/* Get and remove an item from a list at the specified index */
int ll_pop(ll_t *list, int index);
int _ll_pop(ll_node_t **head, int index);


/* Remove all items from a list */
int ll_clear(ll_t *list);
int _ll_clear(ll_node_t **head);


/* Count the number of times an item appears in a list */
int ll_count(ll_t list, int to_count);
int _ll_count(ll_node_t **head, int to_count);


/* Reverse the items in a list */
ll_t *ll_reverse(ll_t *list);
ll_node_t *_ll_reverse(ll_node_t **head, ll_node_t *current);


/* Print all items in a list */
void ll_print(ll_t list);
void _ll_print(ll_node_t *head);


#endif /* LL_H */
