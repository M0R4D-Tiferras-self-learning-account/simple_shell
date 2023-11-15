#include "shell.h"

/**
 * _getenv - Get the value of an environment variable.
 * @name: The name of the environment variable to retrieve.
 *
 * Description:
 * This function searches for the specified environment variable (name) and
 * returns its value. It does this by iterating through the elements in the
 * "environ" array, which contains environment variable strings in the format
 * "NAME=VALUE". The function compares the "NAME" part of each element with the
 * provided name and returns the corresponding "VALUE" if found.
 *
 * Return: The value of the environment variable, or NULL if not found.
 */
char *_getenv(char *name)
{
	char *key = NULL;
	int i;

	/* Iterate through the environment variables */
	for (i = 0; environ[i]; i++)
	{
		/* Split the environment variable into "NAME" and "VALUE" parts */
		key = strtok(environ[i], "=");

		/* Compare "NAME" with the provided name */
		if (strcmp(key, name) == 0)
			return (strtok(NULL, "=")); /* Return "VALUE" part */
	}

	return (NULL); /* Environment variable not found */
}

