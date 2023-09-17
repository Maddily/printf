#include "main.h"

/**
 * fill_buffer - Fills the character buffer
 * @format: A pointer to the format string
 * @count: A pointer to the number of characters added to the buffer
 * @total: A pointer to the number of characters printed
 * @buffer: A pointer to the buffer storing characters
 */
void fill_buffer(const char *format, int *count, int *total, char *buffer)
{
	buffer[*count] = *format;
	(*count)++;
	if (*count == 1024)
	{
		*total += write(1, (const void *)buffer, *count);
		*count = 0;
	}
}
