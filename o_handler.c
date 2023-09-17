#include "main.h"

/**
 * o_format_handler - prints an unsigned octal integer
 * @ap: Argument pointer
 * @count: number of characters printed
 * @total: A pointer to the total number of characters printed
 * @buffer: A pointer to the buffer holding the characters to be printed
 *
 * Return: nothing
 */

void o_format_handler(va_list ap, int *count,
		int *total, char *buffer)
{
	char octal_buffer[32];
	int k, i = 0;
	unsigned int number = va_arg(ap, unsigned int);

	if (number == 0)
	{
		buffer[*count] = '0';
		(*count)++;

		if (*count == 1024)
		{
			*total += write(1, (const void *)buffer, *count);
			*count = 0;
		}
		return;
	}

	while (number != 0)
	{
		octal_buffer[i++] = '0' + (number % 8);
		number /= 8;
	}

	for (k = i - 1; k >= 0 && *total < 1024; k--)
	{
		buffer[*count] = octal_buffer[k];
		(*count)++;

		if (*count == 1024)
		{
			*total += write(1, (const void *)buffer, *count);
			*count = 0;
		}
	}
}
