#include "main.h"

/**
 * get_path - get the path of a command
 * @command: the command to find
 * Return: the path of the command
 *
 */

char *get_path(char *command)
{
	struct stat st;
	int i;
	char *path_env, *path_dir, *fullCmd;

	for (i = 0; command[i]; i++)
	{
		if (command[i] == '/')
		{
			if (stat(command, &st) == 0)
			{
				return (my_strdup(command));
			}
			return (NULL);
		}
	}

	path_env = _getenv("PATH");
	if (!path_env)
		return (NULL);

	path_dir = strtok(path_env, ":");
	while (path_dir)
	{
		fullCmd = malloc(strlen(path_dir) + strlen(command) + 2);
		if (!fullCmd)
			break;

		my_sprintf(fullCmd, "%s/%s", path_dir, command);
		if (stat(fullCmd, &st) == 0)
		{
			free(path_env);
			return (fullCmd);
		}

		free(fullCmd);
		path_dir = strtok(NULL, ":");
	}

	free(path_env);
	return (NULL);
}
