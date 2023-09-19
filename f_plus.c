#include "main.h"

/**
 * f_plus_handler - handles flag [+]
 * only works for %d and %i (numeric specifiers)
 * @format: A pointer to the format string
 * @ap: Argument pointer
 * @count: A pointer to the count of characters in buffer
 * @total: The total number of characters printed
 * @buffer: A pointer to the buffer storing characters to be printed
 *
 * Return: 0 on success, on failure 1
 */

int f_plus_handler(const char *format, va_list ap, int *count,
		int *total, char *buffer)
{
	int num, len;
	(void)format;

	num = va_arg(ap, int);
	len = 0;

	if (num >= 0 || num == 0)
	{
		buffer[*count] = '+';
		(*count)++;
		(*total)++;
		len = my_itoa(format, buffer + *count, num, 10);
	}
	else
	{
		len = my_itoa(format, buffer + *count, num, 10);
	}

	(*count) += len;
	(*total) += len;

	buffer[*count] = '\0';

	return (0);
}

/**
 * f_space_handler - handles flag [' ']
 * only works for %d %i %u %o %x %X (integer specifiers)
 * @format: A pointer to the format string
 * @ap: Argument pointer
 * @count: A pointer to the count of characters in buffer
 * @total: The total number of characters printed
 * @buffer: A pointer to the buffer storing characters to be printed
 *
 * Return: 0 on success, on failure 1
 */

int f_space_handler(const char *format, va_list ap, int *count,
		int *total, char *buffer)
{
	int num, len;
	(void)format;

	num = va_arg(ap, int);
	len = 0;

	if (format[1] == 'o' || format[1] == 'u' || format[1] == 'x'
			|| format[1] == 'X' || format[1] == 'd' || format[1] == 'i')
	{
		if (num >= 0 && (format[1] == 'd' || format[1] == 'i'))
		{
			buffer[*count] = ' ';
			(*count)++;
			(*total)++;
			len = my_itoa(format, buffer + *count, num, 10);
		}
		else
		{
			len = my_itoa(format, buffer + *count, num, 10);
		}

		if (format[1] == 'o')
		{
			len = my_itoa(format, buffer + *count, num, 8);
		}
		else if (format[1] == 'u')
		{
			len = my_itoa(format, buffer + *count, num, 10);
		}
		else if (format[1] == 'x')
		{
			len = my_itoa(format, buffer + *count, num, 16);
		}
		else if (format[1] == 'X')
		{
			len = my_itoa(format, buffer + *count, num, 16);
		}

		(*count) += len;
		(*total) += len;
	}
	else
	{
		return (1);
	}

	buffer[*count] = '\0';

	return (0);
}

