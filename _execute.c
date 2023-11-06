#include "main.h"

/**
 * _execute - Execute a cmd
 * @cmd: Array of strings representing the cmd and its arguments
 * @argv: Array of strings representing program arguments
 *
 * Return: Exit sts of the executed cmd
 */

int _execute(char **cmd, char **argv)
{
	pid_t cld;
	int sts = 0;

	/**
	 * Fork a child process and execute
	 * the child process.It also checks if the child proces
	 * is executed,if not the program exits with an
	 * error code
	 *
	 */

	cld = fork();
	if (cld == 0)
	{
		if (execve(cmd[0], cmd, environ) == -1)
		{
			perror(argv[0]);
			free_str(cmd);
			exit(0);
		}
	}
	/**
	 * This code executes in the parent process
	 *
	 */
	else
	{
		waitpid(cld, &sts, 0);
		free_str(cmd);
	}
	return (WEXITSTATUS(sts));
}
