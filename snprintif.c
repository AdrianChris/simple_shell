#include "main.h"

/**
 * custom_snpt - prints a string if it is not NULL
 * @str: string to print
 * @size: size of str
 * @format: format string
 * @...: arguments
 *
 * Return: number of characters printed
 *
 */

int custom_snpt(char *str, size_t size, const char *format, ...)
{
	va_list args;
	int written;

	va_start(args, format);
	written = vsnprintf(str, size, format, args);
	va_end(args);

	return (written);
}
