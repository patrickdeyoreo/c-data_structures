#include "trash_table.h"

/**
 * trash_tree_del - delete a binary tree
 * @root: a pointer to the root of the tree
 */
void trash_tree_del(trash_node_t *root)
{
	if (root)
	{
		trash_tree_del(root->left);
		trash_tree_del(root->right);
		free(root->key);
		free(root->value);
		free(root);
	}
}

/**
 * trash_table_del - delete a hash table
 * @tt: a pointer to the hash table
 */
void trash_table_del(trash_table_t *tt)
{
	if (tt)
	{
		trash_tree_del(tt->root);
		free(tt->array);
		free(tt);
	}
}
