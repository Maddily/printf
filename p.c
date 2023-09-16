#include "main.h"

/**
 * ptr_format_handler - Handles the %p format specifier
 * @ap: Argument pointer
 * @count: A pointer to the number of printed characters
 * @total: A pointer to the total number of characters printed
 * @buffer: A pointer to the buffer holding the characters to be printed
 */
void ptr_format_handler(va_list ap, int *count, int *total, char *buffer)
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
	hexa_buffer[i] = '0';

	for (j = i; j >= 0; j--)
	{
		buffer[*count] = hexa_buffer[j];
		(*count)++;

		if (*count == 1024)
		{
			total += write(1, (const void *)buffer, *count);
			*count = 0;
		}
	}
}
