#include "main.h"

/**
 * o_format_handler - prints an unsigned octal integer
 * @ap: Argument pointer
 * @count: number of characters printed
 * @total: A pointer to the total number of characters printed
 * @buffer: A pointer to the buffer holding the characters to be printed
 * @field_width: The field width
 * Return: nothing
 */

void o_format_handler(va_list ap, int *count, int *total, char *buffer,
		int field_width)
{
	char octal_buffer[32];
	int k, i = 0;
	unsigned int number = va_arg(ap, unsigned int);

	if (number == 0)
	{
		field_width -= 1;
		field_width_handler(field_width, buffer, count, total);
		buffer[(*count)++] = '0';
		buffer_status_handler(count, total, buffer);
		return;
	}

	while (number != 0)
	{
		octal_buffer[i++] = '0' + (number % 8);
		number /= 8;
	}

	if (field_width > 0)
	{
		field_width -= i;
		field_width_handler(field_width, buffer, count, total);
	}

	for (k = i - 1; k >= 0 && *total < 1024; k--)
	{
		buffer[(*count)++] = octal_buffer[k];
		buffer_status_handler(count, total, buffer);
	}
}
