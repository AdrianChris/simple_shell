#include "main.h"

/**
 * my_error - prints error message
 * @str: name of the file
 * @nm: name of the command
 * @idx: line number
 * Return: void
 */
void my_error(char *str, char *nm, int idx)
{
	char error_message[256];
	char *index, mssg[] = ": not found\n";
	int length;

	index = my_itoa(idx);

	length = sprintf(error_message, "%s: %d: %s%s", str, idx, nm, mssg);
	write(STDERR_FILENO, error_message, length);

	free(index);
}
