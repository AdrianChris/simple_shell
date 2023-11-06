#include "main.h"

/**
 * get_input - Returns a pointer to a character
 * Return: Returns the character
 */

char *get_input(void)
{
	char *m = NULL;
	size_t k = 0;
	ssize_t n;

	/**
	 * Check if the program is executing in
	 * interactive or non-interactive mode
	 *
	 */
	if (isatty(STDIN_FILENO) == 1)
	{
		write(STDOUT_FILENO, "$ ", 2);
	}

	/**
	 * use the getline function to read input
	 */
	n = getline(&m, &k, stdin);
	if (n == -1)
	{
		free(m);
		return (NULL);
	}

	return (m);
}
