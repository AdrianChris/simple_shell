#include "main.h"

/**
 * is_positive_num - checks if a string is a positive number
 * @str: string to check
 *
 * Return: 1 if positive, 0 otherwise
 */

bool is_positive_num(const char *str)
{
	if (!str || *str == '\0')
	{
		return (false);
	}

	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
		{
			return (false);
		}
		str++;
	}

	return (true);
}

/**
 * my_atoi - converts a string to an integer
 * @str: string to convert
 *
 * Return: the converted integer
 */

int my_atoi(char *str)
{
	int i, num = 0;

	for (i = 0; str[i]; i++)
	{
		num *= 10;
		num += (str[i] - '0');
	}
	return (num);
}
