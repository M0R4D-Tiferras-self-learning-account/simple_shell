#include "shell.h"

/**
 * Interactive_shell - This function implements the interactive shell mode.
 */
void Interactive_shell(void)
{
	char **array, *buff = NULL;
	int stat = -1;

	/* Set up a signal handler to handle Ctrl+C (SIGINT) */
	signal(SIGINT, CleanupAndExit);

	/* Infinite loop for the interactive shell */
	while (1)
	{
		/* Display the shell prompt */
		write(1, "$ ", 2);

		/* Read user input */
		buff = Reading_function();

		/* Split the input into an array of commands and arguments */
		array = Spliting_function(buff, " \n\t");

		/* Execute built-in commands or external commands */
		stat = Executing_built_in(array);

		/* Clean up memory */
		free(buff);
		free(array);

		/* If a command returns a positive status, exit the shell */
		if (stat >= 0)
		{
			exit(stat);
		}

		/* Reset the buffer */
		buff = NULL;
	}
}

