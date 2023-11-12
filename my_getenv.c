#include "main.h"

/**
 * _getenv - gets an environment variable
 * @variable: the variable to get
 * Return: the value of the variable
 * or NULL if it doesn't exist
 * or NULL if it fails
 *
 * Description:
 * 1. Get the environment variable
 * 2. Split the environment variable into key and value
 * 3. Compare the key with the variable
 * 4. If it matches, return the value
 * 5. If it doesn't match, return NULL
 * 6. If it fails, return NULL
 */

char *_getenv(char *variable)
{
	char *value;
	int i;
	char *result;

	for (i = 0; environ[i]; i++)
	{
		char *env = my_strdup(environ[i]);
		char *key = strtok(env, "=");

		if (my_strcmp(key, variable) == 0)
		{
			value = strtok(NULL, "=");
			result = my_strdup(value);
			free(env);
			return (result);
		}
		free(env);
	}
	return (NULL);
}
