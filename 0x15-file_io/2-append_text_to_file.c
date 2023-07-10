#include "main.h"

/**
 * append_text_to_file - appends text at the end of a file.
 * @filename: A pointer that points to the name of the file.
 * @text_content: The string to be added to the end of the file.
 * Return: 1 on success and -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int p, m, length = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (length = 0; text_content[length];)
			length++;
	}

	p = open(filename, O_WRONLY | O_APPEND);
	m = write(p, text_content, length);

	if (p == -1 || m == -1)
		return (-1);

	close(p);

	return (1);
}
