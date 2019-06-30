// Function definitions for a linked list node

#include "ll_node.h"


// Create a new node
ll_node_t *ll_node_new(int data, ll_node_t *next)
{
        ll_node_t *new_node = NULL;
	new_node = (ll_node_t *) malloc(sizeof(ll_node_t));
        if (new_node) {
                new_node->data = data;
                new_node->next = next;
        }
        return new_node;
}


// Create a copy of a node
ll_node_t *ll_node_copy(ll_node_t *src)
{
        ll_node_t *new_node = NULL;
        if (src && (new_node = (ll_node_t *) malloc(sizeof(ll_node_t)))) {
                new_node->data = src->data;
                new_node->next = NULL;
        }
        return new_node;
}


// Create a copy of a chain of nodes
ll_node_t *ll_node_copy_all(ll_node_t *src)
{
        ll_node_t *new_node = NULL;
        ll_node_copy_all_to(&new_node, src);
        return new_node;
}


// Copy a chain of nodes to a given destination
size_t ll_node_copy_all_to(ll_node_t **dest, ll_node_t *src)
{
        if (dest == NULL)
                return 0;
        return _ll_node_copy_all_to(dest, src);
}

// Recursively copy nodes from src to dest
size_t _ll_node_copy_all_to(ll_node_t **dest, ll_node_t *src)
{
        if (src == NULL)
                *dest = NULL;
	else
		*dest = ll_node_new(src->data, NULL);
	if (*dest)
		return _ll_node_copy_all_to(&(*dest)->next, src->next) + 1;
        return 0;
}
