#include "main.h"

/**
 * my_getchar - Custom implementation of getchar.
 *
 * Return: Returns the character read or EOF on end-of-file or error.
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
