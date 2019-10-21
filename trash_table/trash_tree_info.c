#include "trash_table.h"

/**
 * trash_tree_height - compute the height of a binary tree
 * @root: a pointer to the root of a tree
 *
 * Return: the height of the tree pointed to by root
 */
size_t trash_tree_height(const trash_node_t *root)
{
	if (root)
		return (1 + max(
			trash_tree_height(root->left),
			trash_tree_height(root->right)
		));
	return (0);
}

/**
 * trash_tree_leaves - count the leaves in a binary tree
 * @root: a pointer to the root of a tree
 *
 * Return: the height of the tree pointed to by root
 */
size_t trash_tree_leaves(const trash_node_t *root)
{
	if (root)
	{
		if (root->left || root->right)
			return (trash_tree_leaves(root->left) +
				trash_tree_leaves(root->right));
		return (1);
	}
	return (0);
}

/**
 * trash_tree_size - count the nodes in a binary tree
 * @root: a pointer to the root of a tree
 *
 * Return: the number of nodes in the tree pointed to by root
 */
size_t trash_tree_size(const trash_node_t *root)
{
	if (root)
		return (trash_tree_size(root->left) +
			trash_tree_size(root->right) + 1);
	return (0);
}
