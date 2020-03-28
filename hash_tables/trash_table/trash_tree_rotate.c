#include "trash_table.h"

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
	(*root)->right->color = BLK;
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
	(*root)->right->color = BLK;
}

/**
 * trash_tree_rotate_right - rotate a subtree to the right
 * @root: a pointer to the root node
 */
void trash_tree_rotate_right(trash_node_t **root)
{
	trash_node_t *tmp = *root;

	(*root) = tmp->left;
	tmp->left = (*root)->right;
	(*root)->right = tmp;

	(*root)->left->color = BLK;
}

/**
 * trash_tree_rotate_right_complex - rotate a subtree to the right
 * @root: a pointer to the root node
 */
void trash_tree_rotate_right_complex(trash_node_t **root)
{
	trash_node_t *tmp = *root;

	(*root) = tmp->left->right;
	tmp->left->right = (*root)->left;
	(*root)->left = tmp->left;
	tmp->left = (*root)->right;
	(*root)->right = tmp;

	(*root)->left->color = BLK;
}
