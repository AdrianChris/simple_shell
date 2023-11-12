#include "main.h"

/**
 * my_strlen - Returns the length of a string
 * @s: String to count
 *
 * Return: String length
 *
 * Description: Counts string length
 *
 */
int my_strlen(const char *const s)
{
	const char *p;
	int length = 0;

	if (s == NULL)
		return (0);

	p = s;
	while (*p != '\0')
	{
		length++;
		p++;
	}

	return (length);
}
