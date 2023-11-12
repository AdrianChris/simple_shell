#include "main.h"

/**
 * handle_character - handle character
 * @outbuf: output buffer
 * @written: number of characters written
 * @fmt: format string
 *
 * Return: number of characters write
 *
 * Description: handle character
 *
 * 1. write character to outbuf
 * 2. increment written
 * 3. increment fmt
 * 4. return
 *
 */
void handle_character(char *outbuf, int *written, const char **fmt)
{
	outbuf[(*written)++] = *(*fmt)++;
}

/**
 * handle_integer - handle integer
 * @outbuf: output buffer
 * @written: number of characters written
 * @args: variable arguments
 * @fmt: format string
 *
 * Return: number of characters write
 *
 */
void handle_integer(char *outbuf, int *written,
					va_list *args, const char **fmt)
{
	int i, num = va_arg(*args, int);
	char numStr[12];

	custom_snpt(numStr, sizeof(numStr), "%d", num);

	while (numStr[i])
	{
		outbuf[(*written)++] = numStr[i++];
	}
	(*fmt)++;
}

/**
 * handle_string - handle string
 * @outbuf: output buffer
 * @written: number of characters written
 * @args: variable arguments
 * @fmt: format string
 *
 * Return: number of characters write
 *
 * Description: handle string
 *
 * 1. get string from args
 * 2. if string is not null
 * 3. while string is not null
 * 4. write character to outbuf
 * 5. increment written
 * 6. increment string
 * 7. increment fmt
 * 8. return
 *
 */
void handle_string(char *outbuf, int *written, va_list *args, const char **fmt)
{
	char *str = va_arg(*args, char *);

	if (str != NULL)
	{
		while (*str)
		{
			outbuf[(*written)++] = *str++;
		}
	}
	(*fmt)++;
}

/**
 * my_sprintf - custom sprintf
 * @outbuf: output buffer
 * @fmt: format string
 * @...: variable arguments
 *
 * Return: number of characters written
 *
 */
int my_sprintf(char *outbuf, const char *fmt, ...)
{
	va_list args;
	int written = 0;

	va_start(args, fmt);
	while (*fmt)
	{
		if (*fmt != '%')
		{
			handle_character(outbuf, &written, &fmt);
			continue;
		}
		fmt++;
		switch (*fmt)
		{
		case 'c':
			outbuf[written++] = (char)va_arg(args, int);
			fmt++;
			break;
		case 'd':
		case 'i':
			handle_integer(outbuf, &written, &args, &fmt);
			break;
		case 's':
			handle_string(outbuf, &written, &args, &fmt);
			break;
		default:
			outbuf[written++] = '%';
			outbuf[written++] = *fmt++;
			break;
		}
	}
	va_end(args);
	outbuf[written] = '\0';
	return (written);
}
