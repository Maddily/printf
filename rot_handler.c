#include "main.h"

/**
 * custom_R_handler - Handles the %R custom format specifier
 * @ap: Argument pointer
 * @count: The number of printed characters
 * @total: A pointer to the total number of characters printed
 * @buffer: A pointer to the buffer holding the characters to be printed
 * @field_width: The field width
 */
void custom_R_handler(va_list ap, int *count, int *total, char *buffer,
		int field_width)
{
	int i, j, len;
	char *string = va_arg(ap, char *);
	char rot1[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char rot2[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";

	UNUSED(field_width);
	if (string == NULL)
		string = "(null)";
	len = find_length(string);
	for (i = 0; i < len; i++)
	{
		if ((string[i] >= 'A' && string[i] <= 'Z') ||
				(string[i] >= 'a' && string[i] <= 'z'))
		{
			for (j = 0; rot1[j] != '\0'; j++)
			{
				if (string[i] == rot1[j])
				{
					buffer[(*count)++] = rot2[j];
					buffer_status_handler(count, total, buffer);
					break;
				}
			}
		}
		else
		{
			buffer[(*count)++] = string[i];
			buffer_status_handler(count, total, buffer);
		}
	}
}
