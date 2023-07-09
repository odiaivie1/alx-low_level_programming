#include "main.h"

/**
 * print_binary - prints the binary representation of a number
 * @n: The number to print in binary
 */
void print_binary(unsigned long int n)
{
	int l, amount = 0;
	unsigned long int now;

	for (l = 63; l >= 0; l--)
	{
		now = n >> l;

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
