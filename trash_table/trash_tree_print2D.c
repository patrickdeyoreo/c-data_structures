#include "trash_table.h"
#include <stdio.h>

#define PADDING 8

/**
 * trash_tree_print2D - print a binary tree in 2D
 * @root: a pointer to the root of a tree
 *
 * Description: This function prints data from the tree pointed to by root
 * to stdout using reverse inorder traversal. The output is a geometrically
 * accurate representation of the tree.
 */
void trash_tree_print2D(const trash_node_t *root)
{
	static size_t padding;
	size_t s = PADDING;

	if (root)
	{
		padding += PADDING;
		trash_tree_print2D(root->right);

		putchar('\n');
		while (s++ < padding)
			putchar(' ');

		if (root->color == RED)
			printf("<R>(%s)\n", root->key);
		else
			printf("<B>(%s)\n", root->key);

		trash_tree_print2D(root->left);
		padding -= PADDING;
	}
}
