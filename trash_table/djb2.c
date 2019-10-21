#include "trash_table.h"

/**
 * djb2 - compute a hash using the djb2 algorithm
 * @str: a string to hash
 *
 * Return: the hash of str
 */
size_t djb2(const unsigned char *str)
{
	size_t hash = 5381;
	unsigned int c = 0;

	while ((c = *str++))
		hash += (hash << 5) + c;

	return (hash);
}
