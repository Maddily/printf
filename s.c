#include "main.h"

/**
 * str_format_handler - Handles the %s format specifier and
 * prints the argument corresponding to it
 * @string: The character provided as an argument
 * @count: The number of printed characters
 * @len: The length of the string
 * @null: A pointer to the string "(null)"
 */
void str_format_handler(char *string, int count, int len, char *null)
{
	if (string != NULL)
	{
		len = find_length(string);
		write(1, string, len);
		count += len;
	}
	else
	{
		write(1, null, 6);
		count += 6;
	}
}
