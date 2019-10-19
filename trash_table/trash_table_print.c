#include "trash_table.h"
#include <stdio.h>

/**
 * trash_tree_print - print the elements in a binary tree
 * @root: a pointer to the root node
 */
void trash_tree_print(const trash_node_t *root)
{
	if (root)
	{
		trash_tree_print(root->left);

		if (root->left)
			fputs(", ", stdout);

		if (root->value)
			printf("'%s': '%s'", root->key, root->value);
		else
			printf("'%s': %s", root->key, root->value);

		if (root->right)
			fputs(", ", stdout);

		trash_tree_print(root->right);
	}
}

/**
 * trash_table_print - print the elements in a hash table
 * @tt: a pointer to the hash table
 */
void trash_table_print(const trash_table_t *tt)
{
	if (tt)
	{
		putchar('{');
		trash_tree_print(tt->root);
		puts("}");
	}
}
