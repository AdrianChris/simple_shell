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
	int i, len = 0;

	if (str == NULL)
	{
		return (NULL);
	}
	while (*str != '\0')
	{
		len++;
		str++;
	}
	str = str - len;
	ptr = malloc(sizeof(char) * (len + 1));
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
