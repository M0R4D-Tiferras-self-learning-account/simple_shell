#include "shell.h"

/**
 * _getchar - Read a character from standard input.
 * This function reads a single character
 * from the standard input (file descriptor 0).
 *
 * Return: The character read or -1 on error or end of input.
 */
int _getchar(void)
{
	char Char;
	int res = read(0, &Char, 1);

	if (res == 1)
		return ((int)Char);
	else
		return (-1);
}

