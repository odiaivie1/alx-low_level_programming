#include "main.h"

/**
 * set_bit - sets the value of a bit to 1 at a given index.
 * @n: A pointer to the number thats to be chamged
 * @index: The index to set to 1
 *
 * Return: 1 (success), -1 (fail)
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = ((1UL << index) | *n);
	return (1);
}
