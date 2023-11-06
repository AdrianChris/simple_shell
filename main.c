#include "main.h"

/**
 * main - This is the  main entry point for the shell
 * @ac: The argument counts
 * @argv: An array of characters to hold the argument counts
 * Return: 0 Always (success)
 */

int main(int ac, char **argv)
{
	char *l = NULL;
	char **cmds = NULL;
	int sts = 0;
	(void)ac;

	while (1)
	{
		l = get_input();

		/* Handle EOF */
		if (l == NULL)
		{
			if (isatty(STDIN_FILENO))
			{
				write(STDOUT_FILENO, "\n", 1);
			}
			return (sts);
		}
		cmds = tokenizer(l);
		if (!cmds)
		{
			continue;
		}

		sts = _execute(cmds, argv);

	}
	return (0);
}
