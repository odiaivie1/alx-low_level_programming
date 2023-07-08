#include "main.h"

/**
 * binary_to_uint - converts a binary number to an unsigned int
 * @b: The string containing the binary number
 * Return: The number that has been converted
 */
unsigned int binary_to_uint(const char *b)
{
	int l;
	unsigned int val = 0;

	if (!b)
		return (0);

	for (l = 0; b[l]; l++)
	{
		if (b[l] < '0' || b[l] > '1')
		return (0);
	val = 2 * val + (b[l] - '0');
	}

	return (val);
}
