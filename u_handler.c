#include "main.h"

/**
 * u_format_handler - handles 'u' specifier
 * @ap: Argument pointer
 * @count: number of characters printed
 * @total: A pointer to the total number of characters printed
 * @buffer: A pointer to the buffer holding the characters to be printed
 *
 * Return: nothing
 */

void u_format_handler(va_list ap, int *count, int *total, char *buffer)
{
	char decimal_buffer[32];
	int m, i = 0;
	unsigned int number = va_arg(ap, unsigned int);

	if (number == 0)
	{
		handle_zero_number(count, total, buffer);
		return;
	}

	while (number != 0)
	{
		decimal_buffer[i++] = '0' + (number % 10);
		number /= 10;
	}

	for (m = i - 1; m >= 0 && *total < 1024; m--)
	{
		buffer[*count] = decimal_buffer[m];
		(*count)++;

		if (*count == 1024)
		{
			*total += write(1, (const void *)buffer, *count);
			*count = 0;
		}
	}
}
