#include "trash_table.h"
#include <string.h>

/**
 * trash_table_clear - empty a table
 * @tt: a pointer to the table
 */
void trash_table_clear(trash_table_t *tt)
{
	if (tt)
	{
		trash_tree_delete(&tt->root);
		memset(tt->array, 0, tt->size * sizeof(*tt->array));
	}
}
