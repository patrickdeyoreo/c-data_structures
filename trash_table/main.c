#include "trash_table.h"
#include <stdio.h>
#include <string.h>

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
		printf("Adding: %s = %s\n", key, val);
		trash_table_set(tt, key, val);
	}

	trash_table_print(tt);
	printf("Elements: %lu\n", trash_tree_node_count(tt->root));
	printf("Height:   %lu\n", trash_tree_height(tt->root));
	printf("Leaves:   %lu\n", trash_tree_leaf_count(tt->root));
	printf("Black path (MIN): %lu\n", trash_tree_black_min(tt->root));
	printf("Black path (MAX): %lu\n", trash_tree_black_max(tt->root));
	trash_tree_print2D(tt->root);

	puts("Deleting dictionary...");
	trash_table_delete(tt);
	return (0);
}
