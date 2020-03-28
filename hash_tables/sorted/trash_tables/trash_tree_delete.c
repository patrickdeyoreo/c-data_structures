#include "trash_table.h"

/**
 * _trash_tree_delete - delete a binary tree (recursion)
 * @root: a pointer to the root of the tree
 */
void _trash_tree_delete(trash_node_t *root)
{
	if (root)
	{
		_trash_tree_delete(root->left);
		_trash_tree_delete(root->right);
		free(root->key);
		free(root->value);
		free(root);
	}
}

/**
 * trash_tree_delete - delete and nullify a binary tree
 * @root: a pointer to the hash table
 */
void trash_tree_delete(trash_node_t **root)
{
	if (root && *root)
	{
		_trash_tree_delete(*root);
		*root = NULL;
	}
}

