#include "trash_table.h"

/**
 * trash_table_new - create a new trash table
 * @size: the size of the array
 *
 * Return: a pointer to the initialized trash table
 */
trash_table_t *trash_table_new(size_t size)
{
	trash_table_t *tt = malloc(sizeof(*tt));

	if (tt)
	{
		tt->array = calloc(size, sizeof(*tt->array));
		if (tt->array)
		{
			tt->root = NULL;
			tt->size = size;
			return (tt);
		}
		free(tt);
	}
	return (NULL);
}
