#include "trash_table.h"
#include <string.h>

/**
 * trash_chain_get - get an element from a singly-linked list
 * @head: a pointer to the singly-linked list
 * @key: a pointer to the element's key
 *
 * Return: a pointer to the element's value, or NULL if the key wasn't found
 */
char *trash_chain_get(const trash_node_t *head, const char *key)
{
	if (head)
	{
		if (strcmp(key, head->key))
			return (trash_chain_get(head->next, key));

		return (head->value);
	}
	return (NULL);
}

/**
 * trash_table_get - get an element from a hash table
 * @tt: a pointer to the hash table
 * @key: a pointer to the element's key
 *
 * Return: a pointer to the element's value, or NULL if the key wasn't found
 */
char *trash_table_get(const trash_table_t *tt, const char *key)
{
	size_t index = 0;

	if (tt && key && *key)
	{
		index = key_index((const unsigned char *) key, tt->size);
		return (trash_chain_get(tt->array[index], key));
	}
	return (NULL);
}
