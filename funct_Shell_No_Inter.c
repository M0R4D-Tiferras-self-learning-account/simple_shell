#include "shell.h"

/**
 * No_Interactive_shell - Run the shell in non-interactive mode.
 *
 * Description:
 * This function is responsible for running the shell in non-interactive mode.
 * It reads commands from the input stream and executes them.
 * If the input is not
 * a terminal (i.e., not interactive), it doesn't display a prompt. It handles
 * built-in commands and external commands, waits for command completion, and
 * exits with the appropriate status code.
 */
void No_Interactive_shell(void)
{
	char **array, *buff = NULL;
	int stat = -1;

	signal(SIGINT, CleanupAndExit);
	/* Register signal handler for interrupt (Ctrl+C) */

	while (1)
	{
		if (isatty(0) != 0)
			/* Check if the input is a terminal (interactive mode) */
			write(1, "$ ", 2);
		/* Display a shell prompt */

		buff = Reading_from_stream();
		/* Read input from the stream (file or pipe) */
		array = Spliting_function(buff, " \n\t");
		/* Split input into command and arguments */
		stat = Executing_built_in(array);
		/* Execute built-in or external commands */

		free(buff);
		free(array);

		if (stat >= 0)
		{
			exit(stat);
			/* Exit the shell with the command's exit status */
		}
		buff = NULL;
	}
}

