#include "trash_table.h"
#include <stdio.h>

/**
 * trash_node_print - print a key-value pair
 * @node: a pointer to the node to print
 */
void trash_node_print(const trash_node_t *node)
{
	if (node)
		printf("    '%s': '%s',\n", node->key, node->value);
}


/**
 * trash_tree_print - apply a function to a binary tree in level-order
 * @root: a pointer to the root node
 */
void trash_tree_print(const trash_node_t *root)
{
	if (root)
	{
		putchar('{');
		putchar('\n');
		trash_tree_level_order(root, trash_node_print);
		putchar('}');
		putchar('\n');
	}
}

