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

int f_plus_handler(const char *format, va_list ap, int* count,
		int* total, char* buffer)
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
			len = my_itoa(buffer + *count, num);
		}
		else
		{
			len = my_itoa(buffer + *count, num);
		}

		(*count) += len;
		(*total) += len;

		buffer[*count] = '\0';

	return (0);
}
