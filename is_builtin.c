#include "main.h"

/**
 * is_builtin - checks if the command is a builtin
 * @cmds: the commands
 * Return: 1 if builtin, 0 if not
 */

bool is_builtin(const char *cmds)
{
	static const char *const builtins[] = {
		"exit", "env", "setenv", "cd", NULL};
	int i;

	for (i = 0; builtins[i]; i++)
	{
		if (my_strcmp(cmds, builtins[i]) == 0)
		{
			return (1);
		}
	}
	return (0);
}

/**
 * handle_builtin - handles builtins
 * @cmds: the commands
 * @argv: the argv
 * @sts: the status
 * @idx: the index
 * Return: void
 */

void handle_builtin(char **cmds, char **argv, int *sts, int idx)
{
	int cmp_result = my_strcmp(cmds[0], "exit");

	if (cmp_result == 0)
	{
		exit_shell(cmds, argv, sts, idx);
	}
	else
	{
		cmp_result = my_strcmp(cmds[0], "env");
		if (cmp_result == 0)
		{
			print_env(cmds, sts);
		}
	}
}

/**
 * exit_shell - exit shell
 * @cmds: the commands
 * @argv: the argv
 * @sts: the status
 * @idx: the index
 * Return: void
 */

void exit_shell(char **cmds, char **argv, int *sts, int idx)
{
	int exit_value = (*sts);

	char mssg[] = ": exit: Illegal number: ";

	if (cmds[1])
	{
		if (is_positive_num(cmds[1]))
		{
			exit_value = my_atoi(cmds[1]);
		}
		else
		{
			char index[12];

			snprintf(index, sizeof(index), "%d", idx);
			write(STDERR_FILENO, argv[0], strlen(argv[0]));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, index, strlen(index));
			write(STDERR_FILENO, mssg, sizeof(mssg) - 1);
			write(STDERR_FILENO, cmds[1], strlen(cmds[1]));
			write(STDERR_FILENO, "\n", 1);
			(*sts) = 2;
			free_str(cmds);
			return;
		}
	}
	free_str(cmds);
	exit(exit_value);
}

/**
 * print_env - prints the environment
 * @cmds: the commands
 * @sts: the status
 * Return: void
 */

void print_env(char **cmds, int *sts)
{
	int i;
	char *env;

	for (i = 0; (env = environ[i]) != NULL; i++)
	{
		size_t len = my_strlen(env) + 1;
		char *str = malloc(len + 1);

		my_strcpy(str, env);
		my_strcat(str, "\n");
		write(STDOUT_FILENO, str, len);
		free(str);
	}

	free_str(cmds);
	(*sts) = 0;
}
