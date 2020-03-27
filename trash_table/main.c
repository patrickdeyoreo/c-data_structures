#include "trash_table.h"
#include <stdio.h>
#include <string.h>

#define TABLESIZE 1123
#define SEPARATOR "---"

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
		fprintf(stderr, "Usage: %s key=value ...\n", *argv);
		return (2);
	}
	puts("Creating table...");
	tt = trash_table_new(TABLESIZE);
	if (!tt)
	{
		fprintf(stderr, "Failed to allocate %zuB\n", sizeof(*tt->array) * TABLESIZE);
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
	puts(SEPARATOR);
	printf("Size  : %lu\n", trash_tree_size(tt->root));
	printf("Height: %lu\n", trash_tree_height(tt->root));
	printf("Leaves: %lu\n", trash_tree_leaves(tt->root));
	puts("Checking tree...");
	if (trash_tree_black_balanced(tt->root))
		puts("The tree is balanced.");
	else
		puts("Oh no! The tree is not balanced!");
	puts(SEPARATOR);
	puts("Deleting table...");
	trash_table_delete(&tt);
	return (0);
}
