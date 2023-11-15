#include "shell.h"

/**
 * my_exit - Handle the "exit" command.
 * @array: An array of command arguments.
 *
 * Description:
 * This function handles the "exit" command. It checks if there is an argument
 * provided (exit status), and if so, converts it to an integer and returns it.
 * If no argument is provided, it returns 0 as the exit status.
 *
 * Return: The exit status (integer).
 */
int my_exit(char **array)
{
	char *str;

	str = array[1];
	if (str != NULL)
		return (_atoi(str)); /* Convert the exit status argument to an integer */
	else
		return (0); /* No exit status provided, return 0 by default */
}

/**
 * my_env - Handle the "env" command.
 * @args: An array of command arguments.
 *
 * Description:
 * This function handles the "env" command. It prints the environment variables
 * to the standard output. It ignores the arguments provided and simply prints
 * the environment variables line by line.
 *
 * Return: Always returns -1 to indicate that the command has been handled.
 */
int my_env(char **args)
{
	char **env;
	(void)(**args); /* Unused argument, suppress compiler warning */

	/* Iterate through environment variables and print them */
	for (env = environ; *env != NULL; env++)
	{
		write(1, *env, _strlen(*env)); /* Print the environment variable */
		write(1, "\n", 1); /* Add a newline character */
	}

	return (-1); /* Command has been handled, return -1 */
}

