#include "main.h"

/**
 * my_getchar - reads a character from stdin
 * Return: the character read
 * Description: reads a character from stdin
 * and returns it
 *
 */

int my_getchar(void)
{
	static char buf[BUFSIZ];
	static char *buf_ptr = buf;
	static ssize_t buf_size;

	char c;

	if (buf_size <= 0)
	{
		buf_size = read(STDIN_FILENO, buf, sizeof(buf));
		buf_ptr = buf;
		if (buf_size <= 0)
		{
			return (EOF);
		}
	}

	c = *buf_ptr++;
	buf_size--;

	return ((unsigned char)c);
}
