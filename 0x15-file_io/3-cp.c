#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int fd);

/**
 * create_buffer - Function that allocates 1024 bytes for buffer.
 * @file: The char buufer name to store file for
 * Return: a pointer to the allocated buffer
 */
char *create_buffer(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buffer);

}

/**
 * close_file - Function that closes file descriptors
 * @fd: The file descriptor thats to be closed
 */
void close_file(int fd)
{
	int u;

	u = close(fd);

	if (u == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - A function that copies a file contents to another file
 * @argc: The amount of arguments thats supplied to the program
 * @argv: Array of pointers to the supposed arguments
 * Return: 0 if successful
 */
int main(int argc, char *argv[])
{
	int from, to, p, m;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = create_buffer(argv[2]);
	from = open(argv[1], O_RDONLY);
	p = read(from, buffer, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || p == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		m = write(to, buffer, p);
			if (to == -1 || m == -1)
			{
				dprintf(STDERR_FILENO,
						"Error: Can't write to %s\n", argv[2]);
				free(buffer);
				exit(99);
			}

		p = read(from, buffer, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);

	} while (p > 0);

	free(buffer);
	close_file(from);
	close_file(to);

	return (0);
}
