#include "shell.h"

/**
 * Executing_commd_function - Execute external commands.
 * @array: An array of command arguments.
 *
 * Description:
 * This function is responsible for executing
 * external commands in the shell.
 *
 * @array: An array of command arguments,
 * typically the command and its arguments.
 *
 * Return: The result of the executed
 * command (exit status or other values).
 */
int Executing_commd_function(char **array)
{
	pid_t pid;
	int j, status;
	static char **environ;
	char *cmd;

	pid = fork();  /* Fork a new process */
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)  /* In the child process */
	{
		cmd = Verifying_path_function(array[0]);
		if (cmd != NULL)
		{
			if (execve(cmd, array, environ) == -1)
			{
				perror(array[0]);  /* Print an error message */
				for (j = 0; array[j]; j++)
					free(array[j]);
				free(array);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			Error_printing(array);  /* Print an error message */
		}
	}
	else  /* In the parent process */
	{
		if (wait(&status) == -1)
		{
			perror("wait");  /* Print an error message */
			exit(EXIT_FAILURE);
		}
	}

	return (-1);  /* Return -1 to indicate completion */
}

