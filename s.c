#include "main.h"

/**
 * str_format_handler - Handles the %s format specifier and
 * prints the argument corresponding to it
 * @ap: Argument pointer
 * @count: The number of printed characters
 * @total: A pointer to the total number of characters printed
 * @buffer: A pointer to the buffer holding the characters to be printed
 * @field_width: The field width
 */
void str_format_handler(va_list ap, int *count, int *total, char *buffer,
		int field_width)
{
	int i, len;
	char *string = va_arg(ap, char *);

	if (string == NULL)
		string = "(null)";

	len = find_length(string);

	if (field_width > 0)
	{
		field_width -= len;
		field_width_handler(field_width, buffer, count, total);
	}

	for (i = 0; i < len; i++)
	{
		buffer[(*count)++] = string[i];
		buffer_status_handler(count, total, buffer);
	}
}
