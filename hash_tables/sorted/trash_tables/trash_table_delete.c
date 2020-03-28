#include "trash_table.h"

/**
 * trash_table_delete - delete and nullify a table
 * @tt: a pointer to the table
 */
void trash_table_delete(trash_table_t **tt)
{
	if (tt && *tt)
	{
		trash_tree_delete(&(*tt)->root);
		free((*tt)->array);
		free(*tt);
		*tt = NULL;
	}
}
