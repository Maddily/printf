#include "main.h"

/**
 * x_format_handler - prints lowercase hexadecimal integers
 * @ap: Argument pointer
 * @count: current count of printed characters
 * @total: A pointer to the total number of characters printed
 * @buffer: A pointer to the buffer holding the characters to be printed
 *
 * Return: nothing
 */

void x_format_handler(va_list ap, int *count,
		int *total, char *buffer)
{
	char hex_buffer[32];
	int i = 0, remainder, k;
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
		remainder = number % 16;
		if (remainder < 10)
			hex_buffer[i++] = '0' + remainder;
		else
			hex_buffer[i++] = 'a' + (remainder - 10);
		number /= 16;
	}

	for (k = i - 1; k >= 0 && *total < 1024; k--)
	{
		buffer[*count] = hex_buffer[k];
		(*count)++;

		if (*count == 1024)
		{
			*total += write(1, (const void *)buffer, *count);
			*count = 0;
		}
	}
}
