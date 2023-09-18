#include "main.h"

/**
 * custom_R_handler - Handles the %R custom format specifier
 * @ap: Argument pointer
 * @count: The number of printed characters
 * @total: A pointer to the total number of characters printed
 * @buffer: A pointer to the buffer holding the characters to be printed
 */
void custom_R_handler(va_list ap, int *count, int *total, char *buffer)
{
	int i, j, len;
	char *string = va_arg(ap, char *);
	char rot1[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char rot2[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";

	if (string == NULL)
		string = "(null)";

	len = find_length(string);

	for (i = 0; i < len; i++)
	{
		for (j = 0; rot1[j] != '\0'; j++)
		{
			if (string[i] == rot1[j])
			{
				buffer[*count] = rot2[j];
				(*count)++;

				if (*count == 1024)
				{
					*total += write(1, (const void *)buffer
							, *count);
					*count = 0;
				}
					break;
			}
		}
	}
}
