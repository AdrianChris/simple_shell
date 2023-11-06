#include "main.h"

/**
 * tokenizer - Splits a string into an array of tokens.
 * @j: The input string to tokenize.
 *
 * Return: An array of pointers to tokens, or NULL if an error occurs.
 */

char **tokenizer(char *j)
{
	char *g = NULL, *z = NULL;
	char **cmd = NULL;
	int i = 0, cpt = 0;

	if (!j)
	{
		return (NULL);
	}

	z = my_strdup(j);
	g = strtok(z, DELIM);
	if (g == NULL)
	{
		free(j), j = NULL;
		free(z), z = NULL;
		return (NULL);
	}

	while (g)
	{
		cpt++;
		g = strtok(NULL, DELIM);
	}
	free(z), z = NULL;
	cmd = malloc(sizeof(char *) * (cpt + 1));
	if (!cmd)
	{
		free(j), j = NULL;
		return (NULL);
	}
	g = strtok(j, DELIM);
	while (g)
	{
		cmd[i] = my_strdup(g);
		g = strtok(NULL, DELIM);
		i++;
	}
	free(j), j = NULL;
	cmd[i] = NULL;
	return (cmd);
}
