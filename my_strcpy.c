#include <stdio.h>

/**
 * my_strcpy - copies a string
 * @dstn: destination
 * @src: source
 * Return: pointer to destination
 *
 */

char *my_strcpy(char *dstn, const char *src)
{
	char *start = dstn;

	while (*src)
	{
		*dstn = *src;
		dstn++;
		src++;
	}
	*dstn = '\0';
	return (start);
}
