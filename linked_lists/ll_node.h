// Structures and function prototypes for a linked list node

#ifndef LL_NODE_H
#define LL_NODE_H

#include <stdlib.h>

// Linked list node structure
typedef struct ll_node {
        int data;
        struct ll_node *next;
} ll_node_t;


// Create a new node
ll_node_t *ll_node_new(int data, ll_node_t *next);

// Create a copy of a node
ll_node_t *ll_node_copy(ll_node_t *src);

// Create a copy of a chain of nodes
ll_node_t *ll_node_copy_all(ll_node_t *src);

// Copy a chain of nodes to a given destination
size_t ll_node_copy_all_to(ll_node_t **dest, ll_node_t *src);
size_t _ll_node_copy_all_to(ll_node_t **dest, ll_node_t *src);


#endif
