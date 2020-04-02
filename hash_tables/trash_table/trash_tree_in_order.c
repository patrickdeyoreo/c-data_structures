#include "trash_table.h"

/**
 * _trash_tree_in_order - apply a function to a binary tree in sorted order
 * @root: a pointer to the root node
 * @func: a function that takes a va_list and returns nothing
 */
void _trash_tree_in_order(
	const trash_node_t *root, void (*func)(const trash_node_t *))
{
	if (root->left)
		_trash_tree_in_order(root->left, func);
	func(root);
	if (root->right)
		_trash_tree_in_order(root->right, func);
}

/**
 * trash_tree_in_order - apply a function to a binary tree in sorted order
 * @root: a pointer to the root node
 * @func: a function that takes a va_list and returns nothing
 */
void trash_tree_in_order(
	const trash_node_t *root, void (*func)(const trash_node_t *))
{
	if (root && func)
		_trash_tree_in_order(root, func);
}

