#include "trash_table.h"

/**
 * key_index - get the index mapped to by a key
 * @key: the key to map to an array index
 * @size: the array size
 *
 * Return: the array index mapped to by key
 */
size_t key_index(const unsigned char *key, size_t size)
{
	return (hash_djb2(key) % size);
}
