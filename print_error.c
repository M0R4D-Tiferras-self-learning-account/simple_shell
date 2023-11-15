#include "shell.h"

/**
 * Error_printing - Print error messages for command not found.
 * @array: An array of command arguments.
 *
 * Description:
 * This function is responsible for printing error messages
 * when a command is not found.
 * It checks if the provided command contains a '/' character.
 * If it does, it assumes that
 * the command is an absolute path and prints an
 * error message accordingly. If there's no
 * '/' character, it prints a "command not found" error.
 *
 * @array: An array of command arguments
 * (usually the command itself and its arguments).
 */
void Error_printing(char **array)
{
	char *string, *bat = NULL;
	int j;

	if (_strchr(array[0], '/') != NULL)
	{
		bat = malloc(sizeof(char) * BUFFER_SIZE);
		if (bat == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		_strcpy(bat, "-bash: ");
		_strcat(bat, array[0]);
		_strcat(bat, ": No such file or directory");
		_puts(bat);  /* Print the error message */
		_putchar('\n');  /* Add a newline character */
		for (j = 0; array[j]; j++)
			free(array[j]);
		free(array);
		free(bat);
		exit(EXIT_FAILURE);
	}
	else
	{
		string = _strcat(array[0], ": command not found");
		_puts(string);  /* Print the error message */
		_putchar('\n');  /* Add a newline character */
		for (j = 0; array[j]; j++)
			free(array[j]);
		free(array);
		exit(EXIT_FAILURE);
	}
}

