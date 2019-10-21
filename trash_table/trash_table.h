#ifndef TRASH_TABLE_H
#define TRASH_TABLE_H

#include <stdlib.h>

/**
 * struct trash_node_s - node for both a hash table and a binary tree
 * @next: the next element in a hash table chain
 * @left: the left subtree of a red-black tree
 * @right: the right subtree of a red-black tree
 * @key: the element's key
 * @value: the element's value
 * @red: red (1) / black (0)
 */
typedef struct trash_node_s
{
	struct trash_node_s *next;
	struct trash_node_s *left;
	struct trash_node_s *right;
	char *key;
	char *value;
	char red;
} trash_node_t;

/**
 * struct trash_table_s - hybrid of a hash table and a binary tree
 * @array: a pointer to an array of singly-linked lists
 * @root:  a pointer to the root of a red-black tree
 * @size:  the size of the array
 *
 * Description: At each array index is a pointer to the first node
 * of a singly-linked list, each of which will be used as the head
 * of a chain of elements for the purpose of resolving collisions.
 * Additionally, a red-black tree connects elements across chains,
 * providing sorted access to the table.
 */
typedef struct trash_table_s
{
	trash_node_t **array;
	trash_node_t *root;
	size_t size;
} trash_table_t;

trash_table_t *trash_table_new(size_t size);
void trash_table_del(trash_table_t *tt);
int trash_table_set(trash_table_t *tt, const char *key, const char *value);
char *trash_table_get(const trash_table_t *tt, const char *key);
void trash_table_print(const trash_table_t *tt);

size_t hash_djb2(const unsigned char *str);
size_t key_index(const unsigned char *key, size_t size);

int trash_tree_insert(trash_node_t **root, trash_node_t *node);
void trash_tree_print(const trash_node_t *root);
void trash_tree_print2D(const trash_node_t *root);
size_t trash_tree_height(const trash_node_t *root);
size_t trash_tree_leaves(const trash_node_t *root);
size_t trash_tree_size(const trash_node_t *root);
size_t trash_tree_black_max(const trash_node_t *root);
size_t trash_tree_black_min(const trash_node_t *root);
size_t trash_tree_black_balanced(const trash_node_t *root);
void trash_tree_rotate_left(trash_node_t **root);
void trash_tree_rotate_left_complex(trash_node_t **root);
void trash_tree_rotate_right(trash_node_t **root);
void trash_tree_rotate_right_complex(trash_node_t **root);

size_t max(size_t a, size_t b);
size_t min(size_t a, size_t b);

#endif /* TRASH_TABLE_H */
