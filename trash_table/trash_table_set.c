#include "trash_table.h"
#include <string.h>

/**
 * trash_node_set - change an element in a singly-linked list
 * @head: a pointer to the singly-linked list
 * @key: a pointer to the element's key
 * @value: a pointer to the element's new value
 *
 * Return: 1 upon success, otherwise 0
 */
int trash_node_set(trash_node_t *head, const char *key, char *value)
{
	if (head)
	{
		if (strcmp(key, head->key))
			return (trash_node_set(head->next, key, value));

		free(head->value);
		head->value = value;
		return (1);
	}
	return (0);
}

/**
 * trash_table_set - set an element in a hash table
 * @tt: a pointer to the hash table
 * @key: a pointer to the element's key
 * @value: a pointer to the element's value
 *
 * Return: 1 upon success, otherwise 0
 */
int trash_table_set(trash_table_t *tt, const char *key, const char *value)
{
	trash_node_t *new_node = NULL;
	char *new_value = NULL;
	size_t index = 0;

	if (!(tt && key && *key))
		return (0);

	if (value)
	{
		new_value = strdup(value);
		if (!new_value)
			return (0);
	}
	index = key_index((const unsigned char *) key, tt->size);
	if (trash_node_set(tt->array[index], key, new_value))
		return (1);

	new_node = malloc(sizeof(*new_node));
	if (!new_node)
	{
		free(new_value);
		return (0);
	}
	new_node->key = strdup(key);
	if (!new_node->key)
	{
		free(new_value);
		free(new_node);
		return (0);
	}
	new_node->value = new_value;
	new_node->next = tt->array[index];
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->red = 1;
	tt->array[index] = new_node;
	trash_tree_insert(&tt->root, new_node);
	tt->root->red = 0;
	return (1);
}
