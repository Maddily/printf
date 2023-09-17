#include "main.h"

/**
 * long_o_handler - prints an unsigned octal integer
 * @number: unsigned octal
 * @count: number of characters printed
 * @total: A pointer to the total number of characters printed
 * @buffer: A pointer to the buffer holding the characters to be printed
 *
 * Return: nothing
 */

void long_o_handler(unsigned long number, int *count,
		int *total, char *buffer)
{
	char octal_buffer[32];
	int k, i = 0;

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
