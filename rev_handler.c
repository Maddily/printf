#include "main.h"

/**
 * custom_r_handler - Handles the %r format specifier
 * @ap: Argument pointer
 * @count: The number of printed characters
 * @total: A pointer to the total number of characters printed
 * @buffer: A pointer to the buffer holding the characters to be printed
 * @field_width: The field width
 */
void custom_r_handler(va_list ap, int *count, int *total, char *buffer,
		int field_width)
{
	int i, len;
	char *string = va_arg(ap, char *);

	UNUSED(field_width);

	if (string == NULL)
		string = "(null)";

	len = find_length(string);

	for (i = len - 1; i >= 0; i--)
	{
		buffer[*count] = string[i];
		(*count)++;

		if (*count == 1024)
		{
			*total += write(1, (const void *)buffer, *count);
			*count = 0;
		}
	}
}
