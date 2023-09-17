#include "main.h"

/**
 * default_handler - Handles the %% and prints '%'
 * @format: A pointer to the format string
 * @count: A pointer to the number of printed characters
 * @total: A pointer to the total number of characters printed
 * @buffer: A pointer to the buffer holding the characters to be printed
 */
void default_handler(const char *format, int *count, int *total, char *buffer)
{
	buffer[*count] = '%';
	(*count)++;

	if (*count == 1024)
	{
		total += write(1, (const void *)buffer, *count);
		*count = 0;
	}

	buffer[*count] = *format;
	(*count)++;

	if (*count == 1024)
	{
		total += write(1, (const void *)buffer, *count);
		*count = 0;
	}
}
