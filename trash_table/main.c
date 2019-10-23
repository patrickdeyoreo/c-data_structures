#include "trash_table.h"
#include <stdio.h>
#include <string.h>

#define TABLESIZE 1123
#define SEPARATOR "---"

/**
 * basename - get the part of a string following the last '/'
 * @str: a pointer to the string to search
 *
 * Return: If '/' was not found, return str.
 * Otherwise, return a pointer to the character following the final '/'.
 */
char *basename(char *str)
{
	char *pos = str;

	if (str)
	{
		while (*str)
		{
			if (*str++ == '/')
				pos = str;
		}
	}
	return (pos);
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
	char *key = NULL, *value = NULL;

	if (argc == 1)
	{
		fprintf(stderr, "usage: %s key=value ...\n", basename(*argv));
		return (2);
	}
	puts("Creating dictionary...");
	tt = trash_table_new(TABLESIZE);
	if (!tt)
	{
		fprintf(stderr, "%s: Not enough memory.\n", basename(*argv));
		return (1);
	}
	puts("Populating dictionary...");
	while ((key = *(++argv)))
	{
		value = strchr(key, '=');
		if (value)
			*value++ = '\0';
		trash_table_set(tt, key, value);
	}
	puts(SEPARATOR);
	trash_table_print(tt);
	puts(SEPARATOR);
	printf("Size  : %lu\n", trash_tree_size(tt->root));
	printf("Height: %lu\n", trash_tree_height(tt->root));
	printf("Leaves: %lu\n", trash_tree_leaves(tt->root));
	if (trash_tree_black_balanced(tt->root))
		puts("Tree is balanced.");
	else
		puts("Tree is not balanced!");
	puts(SEPARATOR);
	puts("Deleting dictionary...");
	trash_table_delete(&tt);
	return (0);
}
