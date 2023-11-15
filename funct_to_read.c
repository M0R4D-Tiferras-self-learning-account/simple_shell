#include "shell.h"

/**
 * Reading_function - Read a line of input from standard input.
 * Return: A pointer to the input line (string).
 */
char *Reading_function(void)
{
	char *buffer = NULL;
	/* Initialize a buffer to store the input line. */
	size_t size = 0;
	/* Initialize the size of the buffer. */
	ssize_t n_chars;

	n_chars = getline(&buffer, &size, stdin);
	/* Read a line from standard input into 'buffer'. */
	if (n_chars == -1)
		/* Check if an error occurred while reading. */
	{
		free(buffer);
		/* Free the allocated buffer. */
		exit(EXIT_FAILURE);
		/* Exit the program with an error status. */
	}
	return (buffer);
	/* Return the input line as a string. */
}

