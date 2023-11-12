#include "main.h"

/**
 * main - Entry point
 * @ac: argument count
 * @argv: argument vector
 * Return: 0 on success
 *
 * Description:
 * 1. get_input: get input from user
 * 2. tokenizer: tokenize input
 * 3. _execute: execute commands
 * 4. get_input: get input from user
 * 5. tokenizer: tokenize input
 * 6. _execute: execute commands
 * 7. get_input: get input from user
 * 8. tokenizer: tokenize input
 * 9. _execute: execute commands
 * 10. get_input: get input from user
 * 11. tokenizer: tokenize input
 */
int main(int ac, char **argv)
{
	char *l = NULL;
	char **cmds = NULL;
	int sts = 0, idx = 0;
	(void)ac;

	while (1)
	{
		l = get_input();

		if (l == NULL)
		{
			if (isatty(STDIN_FILENO))
			{
				write(STDOUT_FILENO, "\n", 1);
			}
			return (sts);
		}
		idx++;
		cmds = tokenizer(l);
		if (!cmds)
		{
			continue;
		}

		sts = _execute(cmds, argv, idx);
	}
	return (0);
}
