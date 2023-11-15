#include "shell.h"

/**
 * Executing_built_in - Execute built-in commands.
 * @array: An array of command arguments.
 *
 * Description:
 * This function is responsible for executing built-in
 * commands in the shell.
 * It compares the command in the provided array with a
 * list of built-in commands,
 * such as "exit" and "env," and calls the corresponding
 * function if a match is found.
 * If the command is not a built-in command, it calls
 * another function for command execution.
 *
 * @array: An array of command arguments, typically the
 * command and its arguments.
 *
 * Return: The result of the executed command (exit status or other values).
 */
int Executing_built_in(char **array)
{
	char *mot_cle[] = {"exit", "env"};

	int (*func_list[])(char **) = {&my_exit, &my_env};

	int i = 0;

	if (array[0] == NULL)
		return (-1);  /* No command provided, return -1 */

	while (i < 2)
	{
		if (_strcmp(array[0], mot_cle[i]) == 0)
			return ((*func_list[i])(array));
		/* Call the corresponding built-in function */
		i++;
	}

	return (Executing_commd_function(array));
}

