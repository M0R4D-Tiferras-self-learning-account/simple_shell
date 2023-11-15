#include "shell.h"

/**
 * CleanupAndExit - Handle cleanup and exit when a signal is received.
 * @signum: The signal number.
 *
 * Description:
 * This function is a signal handler for specific signals, such as SIGINT.
 * When a signal is received, it writes a newline and the shell prompt ('$ ')
 * to the standard output to give the appearance of
 * a clean and responsive shell.
 *
 * @signum: The signal number (unused in this implementation).
 */
void CleanupAndExit(int signum)
{
	(void)signum;  /* Unused variable, suppress compiler warning */
	write(STDOUT_FILENO, "\n", 1);  /* Print a newline character */
	write(STDOUT_FILENO, "$ ", 2);  /* Print the shell prompt ('$ ') */
}

