#include "shell.h"

/**
 * Spliting_function - Split a string into an array
 * of tokens using a specified delimiter.
 * @buffer: The input string to be split.
 * @delemiter: The delimiter used to split the string.
 * Return: A dynamically allocated array of tokens.
 */
char **Spliting_function(char *buffer, char *delemiter)
{
	char **array, *token = NULL;
	int i = 0;

	array = malloc(sizeof(char *) * BUFFER_SIZE);
	if (array == NULL)
	{
		perror("malloc");  /* Print an error message if malloc fails. */
		exit(EXIT_FAILURE);  /* Exit the program with an error status. */
	}
	token = _strtok(buffer, delemiter);
	/* Get the first token from the input string. */
	while (token != NULL)
	{
		if (token[0] == '#')
			break;

		array[i] = token;  /* Store the token in the array. */
		token = _strtok(NULL, delemiter);
		/* Get the next token from the input string. */
		i++;  /* Increment the array index. */
	}
	array[i] = NULL;  /* Terminate the array with a null pointer. */
	return (array);  /* Return the array of tokens. */
}

