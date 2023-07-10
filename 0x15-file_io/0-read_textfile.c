#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - It reads text file print to stdout.
 * @filename: The textfile thats being read.
 * @letters: The number of letters being read.
 * Return: the actual number of letters it could read and print
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *sup;
	ssize_t pd;
	ssize_t m;
	ssize_t f;

	pd = open(filename, O_RDONLY);
	if (pd == -1)
		return (0);
	sup = malloc(sizeof(char) * letters);
	f = read(pd, sup, letters);
	m = write(STDOUT_FILENO, sup, f);

	free(sup);
	close(pd);
	return (m);
}
