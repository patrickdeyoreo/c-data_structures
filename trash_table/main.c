#include "trash_table.h"
#include <stdio.h>
#include <string.h>

#define COUNT 10

/**
 * _trash_tree_print2D - print a binary tree in 2D (helper)
 * @root: a pointer to the root of a subtree
 * @space: the amount of whitespace to print siblings
 *
 * Description: This function performs reverse inorder traversal.
 */
void _trash_tree_print2D(trash_node_t *root, int space)
{
	int i = 0;

	if (root)
	{
		space += COUNT;

		_trash_tree_print2D(root->right, space);

		putchar('\n');
		for (i = COUNT; i < space; i++)
			putchar(' ');
		printf("(%c)%s\n", root->red ? 'R' : 'B', root->key);

		_trash_tree_print2D(root->left, space);
	}
}

/**
 * trash_tree_print2D - print a binary tree in 2D
 * @root: a pointer to the root of a subtree
 */
void trash_tree_print2D(trash_node_t *root)
{
	_trash_tree_print2D(root, 0);
}

/**
 * main - example usage
 * @argc: the argument count
 * @argv: the argument vector
 *
 * Return: 0 upon success, non-zero otherwise
 */
int main(int argc, char **argv)
{
	trash_table_t *tt = NULL;
	char *key = NULL;
	char *val = NULL;
	char *program = strrchr(argv[0], '/');

	if (!program)
		program = argv[0];

	if (argc == 1)
	{
		fprintf(stderr, "Usage: %s key=value ...\n", program);
		return (2);
	}

	puts("Creating dictionary...");
	tt = trash_table_new(1123);
	if (!tt)
	{
		fprintf(stderr, "%s: Dictionary creation failed.\n", program);
		return (1);
	}

	puts("Populating dictionary...");
	while ((key = *(++argv)))
	{
		val = strchr(key, '=');
		if (val)
			*val++ = '\0';
		printf("Adding %s = %s\n", key, val);
		trash_table_set(tt, key, val);
		trash_table_print(tt);
	}
	trash_table_print(tt);

	puts("Deleting dictionary...");
	trash_table_delete(tt);

	return (0);
}
