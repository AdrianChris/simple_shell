#include "main.h"

/**
 * reverse_str - reverses a string
 * @str: string to be reversed
 * @len: length of string
 *
 * Return: void (nothing)
 *
 * Description: reverses a string in place
 *
 * Example:
 *
 * reverse_str("hello", 5);
 *
 * returns:
 *
 * olleh
 *
 */
void reverse_str(char *str, int len)
{
	char tmp;
	int start = 0;
	int end = len - 1;

	while (start < end)
	{
		tmp = str[start];
		str[start] = str[end];
		str[end] = tmp;
		start++;
		end--;
	}
}
