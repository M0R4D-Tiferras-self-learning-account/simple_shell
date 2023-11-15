#include "shell.h"

/**
 * Reading_from_stream - Read a line of input from
 * standard input character by character.
 * Return: A pointer to the input line (string).
 */
char *Reading_from_stream(void)
{
	char *buffer = NULL;
	int Char, i = 0;
	size_t size = BUFFER_SIZE;

	buffer = malloc(sizeof(char *) * BUFFER_SIZE);
	/* Allocate memory for the buffer. */
	if (buffer == NULL)
	{
		perror("malloc");  /* Print an error message if malloc fails. */
		exit(EXIT_FAILURE);  /* Exit the program with an error status. */
	}
	while (1)
	{
		Char = _getchar();  /* Read a character from standard input. */
		if (Char == EOF)  /* Check for end of file (EOF). */
		{
			free(buffer);  /* Free the allocated buffer. */
			exit(EXIT_SUCCESS);  /* Exit the program with a success status. */
		}
		else if (Char == '\n')  /* Check for a newline character. */
		{
			buffer[i] = '\0';  /* Terminate the buffer with a null character. */
			return (buffer);  /* Return the input line as a string. */
		}
		else
			buffer[i] = Char;  /* Store the character in the buffer. */
		i++;
		if (i >= BUFFER_SIZE)  /* Check if the buffer is full. */
		{
			size += size;  /* Increase the buffer size. */
			buffer = malloc(sizeof(char *) * size);
			/* Reallocate memory for the buffer. */
			if (buffer == NULL)
			{
				perror("malloc");  /* Print an error message if malloc fails. */
				exit(EXIT_FAILURE);  /* Exit the program with an error status. */
			}
		}
	}
}

