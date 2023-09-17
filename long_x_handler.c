#include "main.h"

/**
 * long_x_handler - prints lowercase hexadecimal integers
 * @number: unsigned int
 * @count: current count of printed characters
 * @total: A pointer to the total number of characters printed
 * @buffer: A pointer to the buffer holding the characters to be printed
 *
 * Return: nothing
 */

void long_x_handler(unsigned long number, int *count,
		int *total, char *buffer)
{
	char hex_buffer[32];
	int i = 0, remainder, k;

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