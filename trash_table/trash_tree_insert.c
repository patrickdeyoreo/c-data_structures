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
 * ROTATE_R_SUBTREE if right subtree requires rotation
 * ROTATE_L_SUBTREE if left subtree requires rotation
 * BALANCED_ROOT_BLK if subtree is balanced w/ black root
 * BALANCED_ROOT_RED if subtree is balanced w/ red root
 */
trash_tree_state_t trash_tree_insert(trash_node_t **root, trash_node_t *node)
{
	int cmp = 0;

	if (*root)
	{
		cmp = strcmp((*root)->key, node->key);
		switch (cmp > 0 ?
			trash_tree_insert(&((*root)->left), node) :
			trash_tree_insert(&((*root)->right), node))
		{
		case ROTATE_R_SUBTREE:
			if (cmp)
				trash_tree_rotate_right_complex(root);
			else
				trash_tree_rotate_left(root);
			return (BALANCED_ROOT_RED);

		case ROTATE_L_SUBTREE:
			if (cmp)
				trash_tree_rotate_right(root);
			else
				trash_tree_rotate_left_complex(root);
			return (BALANCED_ROOT_RED);

		case BALANCED_ROOT_BLK:
			if ((*root)->color)
				return (BALANCED_ROOT_RED);
			break;

		case BALANCED_ROOT_RED:
			if ((*root)->color)
				return (cmp);
			break;
		}
		return (BALANCED_ROOT_BLK);
	}
	*root = node;
	node->color = RED;
	return (BALANCED_ROOT_RED);
}
