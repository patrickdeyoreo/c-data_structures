#include "trash_table.h"
#include <stdio.h>

#define INCREMENT 10

/**
 * _trash_tree_print2D - print a binary tree in 2D
 * @root: a pointer to the root of a tree
 * @space: the amount of whitespace to put between siblings
 *
 * Description: This function prints data from the tree pointed to by root
 * using reverse inorder traversal. The result is a representation of the
 * tree the tree that is geometrically accurate and visually meaningful.
 */
void _trash_tree_print2D(const trash_node_t *root, size_t space)
{
	size_t i = INCREMENT;

	if (root)
	{
		space += INCREMENT;
		_trash_tree_print2D(root->right, space);

		putchar('\n');
		while (i++ < space)
			putchar(' ');

		printf("<%c> %s\n", root->red ? 'R' : 'B', root->key);
		_trash_tree_print2D(root->left, space);
	}
}

/**
 * trash_tree_print2D - print a binary tree in 2D (wrapper)
 * @root: a pointer to the root of a tree
 */
void trash_tree_print2D(const trash_node_t *root)
{
	_trash_tree_print2D(root, 0);
}
