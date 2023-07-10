#include "main.h"

/**
 * create_file - Function that creates a file
 * @filename: Pointer that point to the file name
 * @text_content: A pointer to a string
 * Return: --1 (fail), else -1
 */
int create_file(const char *filename, char *text_content)
{
	int pd, m, length = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (length = 0; text_content[length];)
			length++;
	}

	pd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	m = write(pd, text_content, length);

	if (pd == -1 || m == -1)
		return (-1);

	close(pd);

	return (1);
}
