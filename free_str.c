#include "main.h"

/**
 * free_str - A function that frees an array of strings
 *
 * @t: This is the array of strings
 *
 */
void free_str(char **t)
{
	int i;

	if (!t)

	{
		return;
	}

	/**
	 *
	 * A for-loop to iterate and
	 * free all strings and the array
	 *
	 */

	for (i = 0; t[i]; i++)
	{
		free(t[i]);
		t[i] = NULL;
	}
	free(t), t = NULL;
}
