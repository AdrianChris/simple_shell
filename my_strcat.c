#include "main.h"

/**
 * my_strcat - concatenates two strings
 * @dt: destination string
 * @src: source string
 *
 * Return: pointer to the resulting string
 *
 * Description: concatenates two strings
 *
 */

char *my_strcat(char *dt, char *src)
{
	char *s = dt;

	if (dt == NULL || src == NULL)
	{
		return (dt);
	}

	while (*s)
	{
		s++;
	}

	while (*src)
	{
		*s = *src;
		s++;
		src++;
	}

	*s = '\0';

	return (dt);
}
