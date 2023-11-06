#include "main.h"

/**
 * get_input - Returns a pointer to a character
 * Return: Returns the character
 */

char *get_input(void)
{
	char *input = NULL;
	int c;
	size_t i = 0;

	if (isatty(STDIN_FILENO) == 1)
	{
		write(STDOUT_FILENO, "$ ", 2);
	}
	while (1)
	{
		c = my_getchar();
		if (c == EOF || c == '\n')
		{
			break;
		}
		input = realloc(input, (i + 1) * sizeof(char));
		if (input == NULL)
		{
			perror("realloc");
			exit(EXIT_FAILURE);
		}
		input[i++] = (char)c;
	}
	if (i == 0 && c == EOF)
	{
		free(input);
		return (NULL);
	}
	if (i == 0)
	{
		return (get_input());
	}
	input = realloc(input, (i + 1) * sizeof(char));
	if (input == NULL)
	{
		perror("realloc");
		exit(EXIT_FAILURE);
	}
	input[i] = '\0';
	return (input);
}
