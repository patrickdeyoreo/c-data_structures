#include "trash_table.h"
#include <string.h>

/**
 * trash_tree_insert - insert a node in a hash table's binary search tree
 * @root: a pointer to the root node
 * @node: a pointer to the new node
 *
 * Description: Recursively insert node in the red-black tree pointed to
 * by root. Re-balance on the way back up.
 *
 * Return:
 * 0 if right subtree requires rotation
 * 1 if left subtree requires rotation
 * 2 if subtree is balanced w/ black root
 * 3 if subtree is balanced w/ red root
 */
int trash_tree_insert(trash_node_t **root, trash_node_t *node)
{
	int cmp = 0;

	if (*root)
	{
		cmp = strcmp(node->key, (*root)->key) < 0;

		switch (cmp ?
			trash_tree_insert(&((*root)->left), node) :
			trash_tree_insert(&((*root)->right), node))
		{
		case 0:
			if (cmp)
				trash_tree_rotate_right_complex(root);
			else
				trash_tree_rotate_left(root);
			return (3);
		case 1:
			if (cmp)
				trash_tree_rotate_right(root);
			else
				trash_tree_rotate_left_complex(root);
			return (3);
		case 2:
			if ((*root)->red)
				return (3);
			break;
		case 3:
			if ((*root)->red)
				return (cmp);
			break;
		}
		return (2);
	}
	*root = node;
	return (3);
}
