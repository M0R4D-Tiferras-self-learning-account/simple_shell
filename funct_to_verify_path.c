#include "shell.h"

/**
 * Verifying_path_function - Verify and return the
 * full path of a given command.
 * @command: The command for which the full path is needed.
 * Return: The full path of the command, or NULL if not found.
 */
char *Verifying_path_function(char *command)
{
	char *path, **path_dirs, *full_path;
	struct stat status;
	int i;

	path = _getenv("PATH");
	/* Get the value of the PATH environment variable. */
	strtok(command, "\n");
	/* Remove newline characters from the command if present. */

	if (_strchr(command, '/') != NULL)
	{
		if (stat(command, &status) == 0)
			return (command);
	}
	else
	{
		path_dirs = Spliting_function(path, ":");
		/* Split the PATH variable into directories. */
		for (i = 0; path_dirs[i]; i++)
		{
			full_path = malloc(_strlen(path_dirs[i]) + _strlen(command) + 2);
			if (full_path == NULL)
			{
				perror("malloc");  /* Print an error message if malloc fails. */
				exit(EXIT_FAILURE);  /* Exit the program with an error status. */
			}
			_strcpy(full_path, path_dirs[i]);
			/* Copy the directory to the full path. */
			_strcat(full_path, "/");  /* Concatenate a '/' to the full path. */
			_strcat(full_path, command);
			/* Concatenate the command to the full path. */
			if (stat(full_path, &status) == 0)  /* Check if the full path exists. */
				return (full_path);  /* If it does, return it as the full path. */
			free(full_path);  /* Free the allocated memory for the full path. */
		}
		free(path_dirs);  /* Free the allocated memory for path_dirs. */
	}
	return (NULL);
}

