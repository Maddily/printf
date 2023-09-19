#include "main.h"

char hex_to_ascii(int digit);

/**
 * str_format_handler - Handles the %s format specifier and
 * prints the argument corresponding to it
 * @ap: Argument pointer
 * @count: The number of printed characters
 * @total: A pointer to the total number of characters printed
 * @buffer: A pointer to the buffer holding the characters to be printed
 * @field_width: The field width
 */
void str_format_handler(va_list ap, int *count, int *total, char *buffer,
		int field_width)
{
	int i, len;
	char *string = va_arg(ap, char *);

	if (string == NULL)
		string = "(null)";

	len = find_length(string);

	if (field_width > 0)
	{
		field_width -= len;
		field_width_handler(field_width, buffer, count, total);
	}

	for (i = 0; i < len; i++)
	{
		buffer[(*count)++] = string[i];
		buffer_status_handler(count, total, buffer);
	}
}

/**
 * char_format_handler - Handles the %c format specifier and
 * prints the argument corresponding to it
 * @ap: Argument pointer
 * @count: A pointer to the number of printed characters
 * @total: A pointer to the total number of characters printed
 * @buffer: A pointer to the buffer holding the characters to be printed
 * @field_width: The field width
 */
void char_format_handler(va_list ap, int *count, int *total, char *buffer,
		int field_width)
{
	char character = (char)va_arg(ap, int);

	if (field_width > 0)
	{
		field_width -= 1;
		field_width_handler(field_width, buffer, count, total);
	}

	buffer[(*count)++] = character;
	buffer_status_handler(count, total, buffer);
}

/**
 * custom_S_handler - prints the string
 * (non printable characters displayed as /x, followed
 * by ASCII code value in hexadecimal)
 *
 * @ap: Argument pointer
 * @count: number of printed characters
 * @total: A pointer to the total number of characters printed
 * @buffer: A pointer to the buffer holding the characters to be printed
 * @field_width: The field width
 */

void custom_S_handler(va_list ap, int *count, int *total, char *buffer,
		int field_width)
{
	int i, len;
	char *string = va_arg(ap, char *);

	UNUSED(field_width);

	if (string != NULL)
	{
		len = find_length(string);
		for (i = 0; i < len; i++)
		{
			if (string[i] < 32 || string[i] >= 127)
			{
				buffer[*count] = '\\';
				(*count)++;
				buffer[*count] = 'x';
				(*count)++;
				buffer[*count] = hex_to_ascii(string[i] / 16);
				(*count)++;
				buffer[*count] = hex_to_ascii(string[i] % 16);
				(*count)++;
			}
			else
			{
				buffer[*count] = string[i];
				(*count)++;
			}

			if (*count == 1024)
			{
				*total += write(1, (const void *)buffer, *count);
				*count = 0;
			}
		}
	}
}

/**
 * hex_to_ascii - Converts a hexadecimal digit to its ASCII
 * @digit: The hexadecimal digit (0-15)
 *
 * Return: The ASCII representation of the hexadecimal digit
 */

char hex_to_ascii(int digit)
{
	if (digit >= 0 && digit <= 9)
		return (digit + '0');
	else if (digit >= 10 && digit <= 15)
		return (digit - 10 + 'A');
	else
		return ('\0');
}
