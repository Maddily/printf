#include "main.h"

/**
 * custom_b_handler - Handles a custom %b format specifier
 * Description: The %b format specifier coverts an unsigned int argument
 * to binary
 * @ap: Argument pointer
 * @count: A pointer to the number of printed characters
 * @total: A pointer to the total number of characters printed
 * @buffer: A pointer to the buffer holding the characters to be printed
 * @field_width: The field width
 */
void custom_b_handler(va_list ap, int *count, int *total, char *buffer,
		int field_width)
{
	unsigned int number;
	char bin[CHAR_BIT * sizeof(unsigned int)];
	int i, j;

	UNUSED(field_width);

	number = va_arg(ap, unsigned int);
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
	if (number > 0)
	{
		i = 0;
		while (number > 0)
		{
			bin[i++] = (number % 2) + '0';
			number /= 2;
		}
		for (j = i - 1; j >= 0; j--)
		{
			buffer[*count] = bin[j];
			(*count)++;

			if (*count == 1024)
			{
				*total += write(1, (const void *)buffer, *count);
				*count = 0;
			}
		}
	}
}
#include "main.h"

/**
 * ptr_format_handler - Handles the %p format specifier
 * @ap: Argument pointer
 * @count: A pointer to the number of printed characters
 * @total: A pointer to the total number of characters printed
 * @buffer: A pointer to the buffer holding the characters to be printed
 * @field_width: The field width
 */
void ptr_format_handler(va_list ap, int *count, int *total, char *buffer,
		int field_width)
{
	void *ptr = va_arg(ap, void *);
	char hexa_chars[] = "0123456789abcdef";
	char hexa_buffer[2048];
	int i = 0, j;
	unsigned long num = (unsigned long)ptr;

	if (ptr == NULL)
	{
		hexa_buffer[i++] = '0';
	}
	else
	{
		while (num != 0)
		{
			hexa_buffer[i++] = hexa_chars[num % 16];
			num /= 16;
		}
	}

	hexa_buffer[i++] = 'x';
	hexa_buffer[i++] = '0';

	if (field_width > 0)
	{
		field_width -= i;
		field_width_handler(field_width, buffer, count, total);
	}
	for (j = i - 1; j >= 0; j--)
	{
		buffer[(*count)++] = hexa_buffer[j];
		buffer_status_handler(count, total, buffer);
	}
}
