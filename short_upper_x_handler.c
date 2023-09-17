#include "main.h"

/**
 * short_upper_x_handler - prints uppercase hexadecimal integers
 * @number: unsigned int
 * @count: current count of printed characters
 * @total: A pointer to the total number of characters printed
 * @buffer: A pointer to the buffer holding the characters to be printed
 *
 * Return: nothing
 */

void short_upper_x_handler(unsigned short number, int *count,
		int *total, char *buffer)
{
	char hex_buffer[32];
	int i = 0, remainder, h;

	if (number == 0) /*check if o*/
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

	while (number != 0) /*convert number to upper hex*/
	{
		remainder = number % 16;
		if (remainder < 10)
			hex_buffer[i++] = '0' + remainder;
		else
			hex_buffer[i++] = 'A' + (remainder - 10);
		number /= 16;
	}

	for (h = i - 1; h >= 0 && *total < 1024; h--)
	{
		buffer[*count] = hex_buffer[h];
		(*count)++;

		if (*count == 1024)
		{
			*total += write(1, (const void *)buffer, *count);
			*count = 0;
		}
	}
}
