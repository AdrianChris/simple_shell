#include "main.h"

/**
 * _execute - executes a command
 * @cmd: command to execute
 * @argv: array of arguments
 * @idx: index of command
 * Return: 0 on success, 127 on failure
 *
 */

int _execute(char **cmd, char **argv, int idx)
{
	pid_t cld;
	int wstatus;
	char *fullCmd;

	fullCmd = get_path(cmd[0]);
	if (!fullCmd)
	{
		my_error(argv[0], cmd[0], idx);
		free_str(cmd);
		return (127);
	}

	cld = fork();

	if (cld == -1)
	{
		perror("fork");
		return (-1);
	}
	if (cld == 0)
	{
		if (execve(fullCmd, cmd, environ) == -1)
		{
			free(fullCmd), fullCmd = NULL;
			free_str(cmd);
			exit(1);
		}
	}
	else
	{
		if (waitpid(cld, &wstatus, 0) == -1)
		{
			perror("waitpid");
			free_str(cmd);
			return (-1);
		}
		free_str(cmd);
		free(fullCmd), fullCmd = NULL;
	}
	return (WEXITSTATUS(wstatus));
}
