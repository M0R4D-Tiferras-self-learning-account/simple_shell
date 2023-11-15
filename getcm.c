#include "shell.h"

/**
 * _fgetc - Read a character from a file descriptor.
 * @fd: The file descriptor from which to read the character.
 *
 * Description:
 * This function reads a single character from the
 * specified file descriptor (fd)
 * using the `read` system call. It checks for errors during the read operation
 * and returns the character read or EOF (End of File)
 * if the end of the file is
 * reached.
 *
 * Return: The character read from the file descriptor,
 * or EOF if the end of the
 * file is reached, or -1 in case of an error.
 */
int _fgetc(int fd)
{
	char Char;
	ssize_t size;

	size = read(fd, &Char, 1);
	if (size == -1)
	{
		perror("read");
		return (-1);  /* Error occurred during read */
	}
	else if (size == 0)
	{
		return (EOF);  /* End of File (EOF) reached */
	}

	return ((int)Char);
}

