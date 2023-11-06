#include "main.h"

/**
 * my_strdup - Duplicates a string.
 *
 * @str: The string to duplicate.
 *
 * Return: A pointer to the duplicated string.
 */

char *my_strdup(const char *str)
{
	char *ptr;
	size_t len = 0, i;

	if (str == NULL)
	{
		return (NULL);
	}

		while (str[len] != '\0')
	{
		len++;
	}
	ptr = (char *)malloc((len + 1) * sizeof(char));

	if (ptr == NULL)
	{
		return (NULL);
	}

	for (i = 0; i <= len; i++)
	{
		ptr[i] = str[i];
	}

	return (ptr);
}
