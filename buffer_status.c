#include "main.h"

/**
 * buffer_status_handler - Prints the buffer if it's full
 * @count: A pointer to the count of characters in the buffer
 * @total: The number of characters printed
 * @buffer: A pointer to the buffer storing characters
 */
void buffer_status_handler(int *count, int *total, char *buffer)
{
	if (*count == 1024)
	{
		*total += write(1, (const void *)buffer, *count);
		*count = 0;
	}
}
