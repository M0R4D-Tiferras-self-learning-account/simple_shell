#include "shell.h"

/**
 * _strtok - Tokenize a string using specified delimiters.
 * @str: The string to tokenize.
 * @del: The delimiters used for tokenization.
 *
 * Description:
 * This function tokenizes a given string (str) into smaller parts based on the
 * specified delimiters (del). It remembers the last position in the string, so
 * you can call it multiple times to extract consecutive tokens.
 *
 * Return: A pointer to the next token in the string or NULL
 * if no more tokens are found.
 */
char *_strtok(char *str, char *del)
{
	static char *last;  /* Static variable to remember the last position */
	char *start, *end;

	/* If str is provided, set last to str; otherwise,*/
	/*check if last is already set */
	if (str)
		last = str;
	else if (!last)
		return (NULL);  /* If str is not provided and last is NULL, no more tokens */

	/* Find the start of the next token by skipping delimiter characters */
	for (start = last; *start != '\0' && _strchr(del, *start) != NULL; start++)
		;

	/* If no more tokens or the string ends, update last and return NULL */
	if (*start == '\0')
	{
		last = NULL;
		return (NULL);
	}

	/* Find the end of the current token by searching for delimiter characters */
	for (end = start; *end != '\0' && _strchr(del, *end) == NULL; end++)
		;

	/* If a delimiter is found, terminate the current token and update last */
	if (*end != '\0')
	{
		*end = '\0';
		last = end + 1;
	}
	else
		last = NULL;

	/* Return a pointer to the start of the current token */
	return (start);
}

