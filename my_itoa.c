#include "main.h"

/**
 * my_itoa - converts integer to string
 * @n: integer to convert
 *
 * Return: pointer to string
 *
 * Description:
 * 1. Allocates memory for string
 * 2. Converts integer to string
 * 3. Reverses string
 * 4. Returns pointer to string
 * 5. Frees memory
 * 6. Exits on error
 * 7. Exits on malloc failure
 * 8. Exits on reverse failure
 * 9. Exits on free failure
 */
char *my_itoa(int n)
{
	const int bufferSize = 20;
	char *buffer = malloc(bufferSize * sizeof(char));
	int i = 0;

	if (buffer == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	if (n == 0)
	{
		buffer[i++] = '0';
	}
	else
	{
		while (n > 0 && i < bufferSize - 1)
		{
			buffer[i++] = (n % 10) + '0';
			n /= 10;
		}
	}
	buffer[i] = '\0';
	reverse_str(buffer, i);
	return (buffer);
}
