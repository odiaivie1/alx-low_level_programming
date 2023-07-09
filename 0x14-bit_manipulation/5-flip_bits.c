#include "main.h"

/**
 * flip_bits - function that returns the number of bits you would
 * need to flip to get from one number to another.
 * @n: The first number
 * @m: The second number
 *
 * Return: The number of bits to change
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int i, amount = 0;
	unsigned long int now;
	unsigned long int extra = n ^ m;

	for (i = 63; i >= 0; i--)
	{
		now = extra >> i;
		if (now & 1)
			amount++;
	}

	return (amount);
	
}
