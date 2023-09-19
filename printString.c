#include "main.h"

char hex_to_ascii(int digit);

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
