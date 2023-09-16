#include "main.h"

/**
 * char_format_handler - Handles the %c format specifier and
 * prints the argument corresponding to it
 * @ap: Argument pointer
 * @count: A pointer to the number of printed characters
 * @total: A pointer to the total number of characters printed
 * @buffer: A pointer to the buffer holding the characters to be printed
 */
void char_format_handler(va_list ap, int *count, int *total, char *buffer)
{
	char character = (char)va_arg(ap, int);

	if (character != '\0')
	{
		buffer[*count] = character;
		(*count)++;

		if (*count == 1024)
		{
			total += write(1, (const void *)buffer, *count);
			*count = 0;
		}
	}
}
