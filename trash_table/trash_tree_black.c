#include "trash_table.h"

/**
 * trash_tree_black_max - find the maximum number of black nodes in a path
 * @root: a pointer to the root of a tree
 *
 * Return: the greatest number of black nodes in any path from root to a leaf
 */
size_t trash_tree_black_max(const trash_node_t *root)
{
	if (root)
		return (!root->red + max(
			trash_tree_black_max(root->left),
			trash_tree_black_max(root->right)
		));
	return (0);
}

/**
 * trash_tree_black_min - find the minimum number of black nodes in a path
 * @root: a pointer to the root of a tree
 *
 * Return: the least number of black nodes in any path from root to a leaf
 */
size_t trash_tree_black_min(const trash_node_t *root)
{
	if (root)
		return (!root->red + min(
			trash_tree_black_min(root->left),
			trash_tree_black_min(root->right)
		));
	return (0);
}

/**
 * trash_tree_black_balanced - check if the black nodes in a tree are balanced
 * @root: a pointer to the root of a tree
 *
 * Description: Every path to a leaf must have the same number of black nodes.
 *
 * Return: 1 if all every path from
 */
size_t trash_tree_black_balanced(const trash_node_t *root)
{
	if (root)
		return (trash_tree_black_max(root) ==
			trash_tree_black_min(root) &&
			trash_tree_black_balanced(root->left) &&
			trash_tree_black_balanced(root->right));
	return (1);
}
