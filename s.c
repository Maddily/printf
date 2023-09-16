#include "main.h"

/**
 * str_format_handler - Handles the %s format specifier and
 * prints the argument corresponding to it
 * @string: The character provided as an argument
 * @count: The number of printed characters
 * @total: A pointer to the total number of characters printed
 * @buffer: A pointer to the buffer holding the characters to be printed
 *
 */
void str_format_handler(char *string, int *count, int *total, char *buffer)
{
	int i, len;

	if (string != NULL)
	{
		len = find_length(string);
		for (i = 0; i < len; i++)
		{
			buffer[*count] = string[i];
			(*count)++;
			
			if (*count == 1024)
			{
				total += write(1, (const void *)buffer, *count);
				*count = 0;
			}
		}
	}
}
