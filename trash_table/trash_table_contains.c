#include "trash_table.h"
#include <string.h>

/**
 * trash_list_contains - check if a key exists in a linked list
 * @ls: a pointer to the list
 * @key: a pointer to the key
 *
 * Return: 1 if the key was found, otherwise 0
 */
int trash_list_contains(const trash_node_t *ls, const char *key)
{
	return (ls && (
		strcmp(key, ls->key) == 0 ||
		trash_list_contains(ls->next, key)
	));
}

/**
 * trash_table_contains - check if a key exists in a hash table
 * @tt: a pointer to the table
 * @key: a pointer to the key
 *
 * Return: 1 if the key was found, otherwise 0
 */
int trash_table_contains(const trash_table_t *tt, const char *key)
{
	return (tt && key && trash_list_contains(
		tt->array[hash(key, tt->size)], key
	));
}
