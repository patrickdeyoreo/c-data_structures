#ifndef TRASH_TABLE_H
#define TRASH_TABLE_H

#include <stdlib.h>

/**
 * enum trash_node_color_n - mneumonic for node color
 * @BLK: black node
 * @RED: red node
 */
typedef enum trash_node_color_n
{
	BLK = 0,
	RED = 1
} trash_node_color_t;

/**
 * enum trash_tree_state_n - mneumonic for possible tree states
 * @ROTATE_R_SUBTREE: right subtree requires rotation
 * @ROTATE_L_SUBTREE: left subtree requires rotation
 * @BALANCED_BLK: tree is balanced with a black root
 * @BALANCED_RED: tree is balanced with a red root
 */
typedef enum trash_tree_state_n
{
	ROTATE_R_SUBTREE = 0,
	ROTATE_L_SUBTREE = 1,
	BALANCED_ROOT_BLK = 2,
	BALANCED_ROOT_RED = 3
} trash_tree_state_t;

/**
 * struct trash_node_s - node for a chained hash table & a red-black tree
 * @next: pointer to the next item in a chain
 * @left: pointer to the left subtree
 * @right: pointer to the right subtree
 * @key: element's key
 * @value: element's value
 * @color: node color (either red or black)
 */
typedef struct trash_node_s
{
	char *key;
	char *value;
	struct trash_node_s *next;
	struct trash_node_s *left;
	struct trash_node_s *right;
	trash_node_color_t color;
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
void trash_table_delete(trash_table_t **tt);
int trash_table_set(trash_table_t *tt, const char *key, const char *value);
int trash_table_contains(const trash_table_t *tt, const char *key);
char *trash_table_get(const trash_table_t *tt, const char *key);
void trash_table_print(const trash_table_t *tt);
void trash_table_clear(trash_table_t *tt);

size_t djb2(const unsigned char *str);
size_t hash(const char *key, size_t size);

void trash_tree_delete(trash_node_t **tt);
trash_tree_state_t trash_tree_insert(trash_node_t **root, trash_node_t *node);
int trash_list_contains(const trash_node_t *ls, const char *key);
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
