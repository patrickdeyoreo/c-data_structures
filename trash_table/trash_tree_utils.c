#include "trash_table.h"

/**
 * trash_tree_height - compute the height of a binary tree
 * @root: a pointer to the root of a subtree
 */
size_t trash_tree_height(const trash_node_t *root)
{
	if (root)
	{
		return (1 + max(
			trash_tree_height(root->left),
			trash_tree_height(root->right)
		));
	}
	return (0);
}

/**
 * trash_tree_leaf_count - count the leaves in a binary tree
 * @root: a pointer to the root of a subtree
 */
size_t trash_tree_leaf_count(const trash_node_t *root)
{
	if (root)
	{
		if (root->left || root->right)
		{
			return (trash_tree_leaf_count(root->left) +
				trash_tree_leaf_count(root->right));
		}
		return (1);
	}
	return (0);
}

/**
 * trash_tree_node_count - count the nodes in a binary tree
 * @root: a pointer to the root of a subtree
 */
size_t trash_tree_node_count(const trash_node_t *root)
{
	if (root)
	{
		return (1 + (
			trash_tree_node_count(root->left) +
			trash_tree_node_count(root->right)
		));
	}
	return (0);
}

/**
 * trash_tree_black_max - find the maximum number of black nodes in a path
 * @root: a pointer to the root of a subtree
 */
size_t trash_tree_black_max(const trash_node_t *root)
{
	if (root)
	{
		return (!root->red + max(
			trash_tree_black_max(root->left),
			trash_tree_black_max(root->right)
		));
	}
	return (0);
}

/**
 * trash_tree_black_min - find the minimum number of black nodes in a path
 * @root: a pointer to the root of a subtree
 */
size_t trash_tree_black_min(const trash_node_t *root)
{
	if (root)
	{
		return (!root->red + min(
			trash_tree_black_min(root->left),
			trash_tree_black_min(root->right)
		));
	}
	return (0);
}
