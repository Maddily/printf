#include "main.h"

/**
 * percent_handler - Handles the %% and prints '%'
 * @count: A pointer to the number of printed characters
 * @total: A pointer to the total number of characters printed
 * @buffer: A pointer to the buffer holding the characters to be printed
 */
void percent_handler(int *count, int *total, char *buffer)
{
	buffer[*count] = '%';
	(*count)++;

	if (*count == 1024)
	{
		*total += write(1, (const void *)buffer, *count);
		*count = 0;
	}
}
