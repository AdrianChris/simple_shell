#include "main.h"

/**
 * my_strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter.
 * @str: string to be copied
 *
 * Return: NULL in case of error, pointer to allocated space
 *
 * Description: The _strdup() function returns a pointer to a new string
 * which is a duplicate of the string str. Memory for the new string is
 * obtained with malloc, and can be freed with free.
 * Returns NULL if str = NULL
 * On success, the _strdup function returns a pointer to the duplicated string.
 * It returns NULL if insufficient memory was available
 *
 */
char *my_strdup(const char *str)
{
	size_t len;
	char *ptr;

	if (str == NULL)
	{
		return (NULL);
	}

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}

	ptr = (char *)malloc(len + 1);
	if (ptr == NULL)
	{
		return (NULL);
	}

	my_strcpy(ptr, str);
	return (ptr);
}
