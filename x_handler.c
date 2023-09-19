#include "main.h"

/**
 * printUpperHex - prints uppercase hexadecimal integers
 * @ap: Argument pointer
 * @count: current count of printed characters
 * @total: A pointer to the total number of characters printed
 * @buffer: A pointer to the buffer holding the characters to be printed
 * @field_width: The field width
 * Return: nothing
 */

void printUpperHex(va_list ap, int *count, int *total, char *buffer,
		int field_width)
{
	char hex_buffer[32];
	int i = 0, remainder, h;
	unsigned int number = va_arg(ap, unsigned int);

	if (number == 0) /*check if o*/
	{
		field_width -= 1;
		field_width_handler(field_width, buffer, count, total);
		buffer[(*count)++] = '0';
		buffer_status_handler(count, total, buffer);
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

	if (field_width > 0)
	{
		field_width -= i;
		field_width_handler(field_width, buffer, count, total);
	}

	for (h = i - 1; h >= 0 && *total < 1024; h--)
	{
		buffer[(*count)++] = hex_buffer[h];
		buffer_status_handler(count, total, buffer);
	}
}
