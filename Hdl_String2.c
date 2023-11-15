#include "shell.h"

/**
 * _strdup - Duplicate a string.
 * @source: The source string to duplicate.
 * Return: A duplicated string, or NULL if allocation fails.
 */
char *_strdup(char *source)
{
	size_t length = _strlen(source) + 1;
	char *dup = (char *)malloc(sizeof(char) * length);

	if (dup != NULL)
	{
		_strcpy(dup, source);
	}
	return (dup);
}

/**
 * _strcmp - Compare two strings.
 * @s1: The first string.
 * @s2: The second string.
 * Return: An integer representing the comparison result.
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/**
 * _strchr - Search for a character in a string.
 * @str: The string to search.
 * @c: The target character.
 * Return: A pointer to a str,or NULL if not found.
*/

char *_strchr(char *str, char c)
{
	while (*str != '\0')
	{
		if (*str == c)
		{
			return (str);
		}
		str++;
	}
	if (c == '\0')
	{
		return (str);
	}
	return (NULL);
}

/**
 * _atoi - Convert a string to an integer.
 * @s: The input string.
 * Return: The integer value parsed from the string.
 */
int _atoi(char *s)
{
	unsigned int n = 0;
	int sig = 1;

	while (*s != '\0')
	{
		if (*s == '-')
		{
			sig = sig * (-1);
		}
		else if (*s >= '0' && *s <= '9')
		{
			n = (n * 10) + (*s - '0');
		}
		else if (n > 0)
		{
			break;
		}
		s++;
	}
	return (n * sig);
}
