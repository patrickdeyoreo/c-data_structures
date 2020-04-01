#include "trash_table.h"
#include <stdio.h>

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
