#include "trash_table.h"
#include <string.h>

/**
 * trash_tree_rotate_left - rotate a subtree to the left
 * @root: a pointer to the root node
 */
void trash_tree_rotate_left(trash_node_t **root)
{
	trash_node_t *tmp = *root;

	*root = tmp->right;
	tmp->right = (*root)->left;
	(*root)->left = tmp;

	(*root)->right->red = 0;
}

/**
 * trash_tree_rotate_left_complex - rotate a subtree to the left
 * @root: a pointer to the root node
 */
void trash_tree_rotate_left_complex(trash_node_t **root)
{
	trash_node_t *tmp = *root;

	*root = tmp->right->left;
	tmp->right->left = (*root)->right;
	(*root)->right = tmp->right;
	tmp->right = (*root)->left;
	(*root)->left = tmp;

	(*root)->right->red = 0;
}

/**
 * trash_tree_rotate_right - rotate a subtree to the right
 * @root: a pointer to the root node
 */
void trash_tree_rotate_right(trash_node_t **root)
{
	trash_node_t *tmp = *root;

	*root = tmp->left;
	tmp->left = (*root)->right;
	(*root)->right = tmp;

	(*root)->left->red = 0;
}

/**
 * trash_tree_rotate_right_complex - rotate a subtree to the right
 * @root: a pointer to the root node
 */
void trash_tree_rotate_right_complex(trash_node_t **root)
{
	trash_node_t *tmp = *root;

	*root = tmp->left->right;
	tmp->left->right = (*root)->left;
	(*root)->left = tmp->left;
	tmp->left = (*root)->right;
	(*root)->right = tmp;

	(*root)->left->red = 0;
}

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
