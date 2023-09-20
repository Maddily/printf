#include "main.h"

/**
 * field_width_handler - Handles the field width
 * @field_width: The field width
 * @buffer: A pointer to the buffer holding the characters to be printed
 * @count: A pointer to the current count of printed characters
 * @total: A pointer to the total number of characters printed
 */
void field_width_handler(int field_width, char *buffer, int *count, int *total)
{
	if (field_width > 0)
	{
		while (field_width > 0)
		{
			buffer[*count] = ' ';
			(*count)++;
			field_width--;

			buffer_status_handler(count, total, buffer);
		}
	}
}
