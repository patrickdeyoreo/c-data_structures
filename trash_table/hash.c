#include "trash_table.h"

/**
 * hash - get the index mapped to by a key
 * @key: the key to map to an array index
 * @size: the array size
 *
 * Return: the array index mapped to by key
 */
size_t hash(const unsigned char *key, size_t size)
{
	return (djb2(key) % size);
}
