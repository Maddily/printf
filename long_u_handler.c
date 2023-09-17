#include "main.h"

/**
 * long_u_handler - handles 'u' specifier
 * @number: unsigned int
 * @count: number of characters printed
 * @total: A pointer to the total number of characters printed
 * @buffer: A pointer to the buffer holding the characters to be printed
 *
 * Return: nothing
 */

void long_u_handler(unsigned long number, int *count,
		int *total, char *buffer)
{
	char decimal_buffer[32];
	int m, i = 0;

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
