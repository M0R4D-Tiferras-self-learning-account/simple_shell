#include "shell.h"

/**
 * main - The main entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings containing the command-line arguments.
 * @env: An array of strings containing the environment variables.
 * Return: The exit status of the program
*/

int	main(int argc, char **argv, char **env)
{
	/* Suppress unused parameter warnings */
	(void)argc;
	(void)argv;
	(void)env;

	/* Check if the standard input is a terminal (interactive mode) */
	if (isatty(STDIN_FILENO) == 1)
	{
		Interactive_shell();
	}
	else
	{
		No_Interactive_shell();
	}

	/* Return an exit status of 0 to indicate successful execution */
	return (0);
}
