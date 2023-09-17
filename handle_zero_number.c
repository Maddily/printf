#include "main.h"

/**
 * handle_zero_number - handles case if input is zero
 * @count: number of characters printed
 * @total: A pointer to the total number of characters printed
 * @buffer: A pointer to the buffer holding the characters to be printed
 */
void handle_zero_number(int *count, int *total, char *buffer)
{
	buffer[*count] = '0';
	(*count)++;

	if (*count == 1024)
	{
		*total += write(1, (const void *)buffer, *count);
		*count = 0;
	}
}
