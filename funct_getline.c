#include "shell.h"

/**
 * _getline - Read a line from a file descriptor.
 * @buffer: Pointer to store the line.
 * @n: Pointer to store the line length.
 * @fd: File descriptor to read from.
 *
 * Description:
 * This function reads a line of text from the specified file descriptor (fd).
 * It dynamically allocates memory for the line
 * and updates the buffer and length
 * pointers accordingly. The function continues reading
 * until it reaches the end of
 * the file or encounters a newline character.
 * It dynamically adjusts the buffer size
 * to accommodate long lines.
 *
 * Return: The length of the line read, or -1 on error or end of input.
 */
ssize_t _getline(char **buffer, size_t *n, int fd)
{
	int c;
	size_t length = 0, size;
	char *new_buffer;

	size = BUFFER_SIZE;
	if (buffer == NULL || n == 0)
		return (-1);
	*buffer = malloc(sizeof(char *) * BUFFER_SIZE);
	if (*buffer == NULL)
	{
		perror("malloc");
		return (-1);
	}
	while ((c = _fgetc(fd)) != EOF)
	{
		if (length >= BUFFER_SIZE - 1)
		{
			size += size;
			new_buffer = malloc(sizeof(char *) * size);
			if (new_buffer == NULL)
			{
				perror("malloc");
				return (-1);
			}
			*buffer = new_buffer;
		}
		(*buffer)[length] = (char)c;
		if (c == '\n')
			break;
		length++;
	}
	(*buffer)[length] = '\0';
	*n = length;
	if (length > 0)
		return (length);
	else
		return (-1);
}
