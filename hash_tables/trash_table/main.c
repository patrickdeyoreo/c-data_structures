#include "trash_table.h"
#include <stdio.h>
#include <string.h>

#define TABLESIZE 1123
#define SEPARATOR "----------------"

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
	char *key = NULL, *value = NULL;

	if (argc == 1)
	{
		fprintf(stderr, "usage: %s key=value ...\n",
			*argv);
		return (2);
	}
	puts("Allocating...");
	tt = trash_table_new(TABLESIZE);
	if (!tt)
	{
		fprintf(stderr, "Failed to allocate %zd bytes\n",
			sizeof(*tt->array) * TABLESIZE);
		return (1);
	}
	puts("Populating...");
	while ((key = *(++argv)))
	{
		value = strchr(key, '=');
		if (value)
			*value++ = '\0';
		trash_table_set(tt, key, value);
	}
	puts("Printing...");
	trash_tree_print_sorted(tt->root);
	puts("Evaluating...");
	puts(SEPARATOR);
	printf("%-8s: %lu\n", "Size", trash_tree_size(tt->root));
	printf("%-8s: %lu\n", "Height", trash_tree_height(tt->root));
	printf("%-8s: %lu\n", "Leaves", trash_tree_leaves(tt->root));
	if (trash_tree_black_balanced(tt->root))
		printf("%-8s: Yes\n", "Balanced");
	else
		printf("%-8s: No\n", "Balanced");
	puts(SEPARATOR);
	puts("Deleting...");
	trash_table_delete(&tt);
	return (0);
}
