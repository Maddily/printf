#include "main.h"

/**
 * char_format_handler - Handles the %c format specifier and
 * prints the argument corresponding to it
 * @ap: Argument pointer
 * @count: A pointer to the number of printed characters
 * @total: A pointer to the total number of characters printed
 * @buffer: A pointer to the buffer holding the characters to be printed
 * @field_width: The field width
 */
void char_format_handler(va_list ap, int *count, int *total, char *buffer,
		int field_width)
{
	char character = (char)va_arg(ap, int);

	if (field_width > 0)
	{
		field_width -= 1;
		field_width_handler(field_width, buffer, count, total);
	}

	buffer[(*count)++] = character;
	buffer_status_handler(count, total, buffer);
}
