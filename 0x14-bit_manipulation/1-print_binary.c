#include "main.h"

/**
 * print_binary - prints the binary representation of a number
 * @n: The number to print in binary
 */
void print_binary(unsigned long int n)
{
	int i, amount = 0;
	unsigned long int now;

	for (i = 63; i >= 0; i--)
	{
		now = n >> i;

		if (now & 1)
		{
			_putchar('1');
			now++;
		}
		else if (now)
			_putchar('0');
	}
	if (!now)
		_putchar('0');
}
