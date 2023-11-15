#include "shell.h"

/**
 * _putchar - Write a single character to the standard output.
 *
 * @c: The character to be written.
 * Return: The number of characters written
 * (always 1 for a single character).
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
	/* Write the character 'c' to standard output */
}

/**
 * _puts - Write a string to the standard output.
 *
 * @str: The string to be written.
 * Return: The number of characters written (string length).
 */
int _puts(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
	{
		_putchar(str[i]);
		/* Write each character of the string to standard output */
	}
	return (i);
	/* Return the number of characters written (string length) */
}
