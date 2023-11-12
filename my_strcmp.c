#include "main.h"

/**
 * my_strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: 0 if s1 and s2 are equal,
 *         negative if s1 is less than s2
 *         positive if s1 is greater than s2
 *         or -1 if s1 or s2 is NULL
 *
 * Description: compares two strings
 *              using the strcmp function
 *              from the standard library
 *              but without using the strcmp function
 *              from the standard library
 *              and without using any other functions
 *              from the standard library
 */
int my_strcmp(const char *s1, const char *s2)
{
	if (s1 == NULL || s2 == NULL)
	{
		return (-1);
	}

	while (*s1 && *s2)
	{
		if (*s1 != *s2)
		{
			return ((*s1 < *s2) ? -1 : 1);
		}
		s1++;
		s2++;
	}

	if (*s1 == '\0' && *s2 == '\0')
	{
		return (0);
	}
	else
	{
		return ((*s1 == '\0') ? -1 : 1);
	}
}
