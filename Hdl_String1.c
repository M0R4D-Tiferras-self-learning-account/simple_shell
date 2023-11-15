#include "shell.h"

/**
 * _strcpy - Copy the source string into the destination string.
 * @dest: The destination string.
 * @src: The source string.
 * Return: The destination string after copying.
*/

char	*_strcpy(char *dest, char *src)
{
	int i = 0, j = 0;

	/* Calculate the length of the source string. */
	while (*(src + i) != '\0')
		i++;

	/* Copy the characters from source to destination. */
	for (j = 0; j < i; j++)
		dest[j] = src[j];

	dest[i] = '\0';  /* Null-terminate the destination string. */
	return (dest);
}

/**
 * _strcat - Concatenate two strings.
 * @dest: The destination string.
 * @src: The source string to concatenate.
 * Return: The destination string after concatenation.
 */
char *_strcat(char *dest, char *src)
{
	int i, j = 0;

	/* Find the null terminator position in the destination string. */
	for (i = 0; dest[i]; i++)
		;

	/* Concatenate characters from source to destination. */
	for (j = 0; *(src + j) != '\0'; j++)
	{
		*(dest + i) = *(src + j);
		i++;
	}

	dest[i] = '\0';  /* Null-terminate the destination string. */
	return (dest);
}

/**
 * _strlen - Calculate the length of a string.
 * @str: The input string.
 * Return: The length of the string.
*/

int	_strlen(char *str)
{
	int i = 0;

	/* Count the characters in the string until the null terminator is found. */
	while (str[i])
		i++;

	return (i);
}
