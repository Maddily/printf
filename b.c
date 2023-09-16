#include "main.h"

/**
 * custom_b_handler - Handles a custom %b format specifier
 * Description: The %b format specifier coverts an unsigned int argument
 * to binary
 * @ap: Argument pointer
 * @count: A pointer to the number of printed characters
 * @total: A pointer to the total number of characters printed
 * @buffer: A pointer to the buffer holding the characters to be printed
 */
void custom_b_handler(va_list ap, int *count, int *total, char *buffer)
{
	unsigned int number;
	char bin[CHAR_BIT * sizeof(unsigned int)];
	int i, j;

	number = va_arg(ap, unsigned int);
	if (number == 0)
	{
		buffer[*count] = '0';
		(*count)++;

		if (*count == 1024)
		{
			total += write(1, (const void *)buffer, *count);
			*count = 0;
		}
		return;
	}
	if (number > 0)
	{
		i = 0;
		while (number > 0)
		{
			bin[i++] = (number % 2) + '0';
			number /= 2;
		}
		for (j = i - 1; j >= 0; j--)
		{
			buffer[*count] = bin[j];
			(*count)++;
			
			if (*count == 1024)
			{
				total += write(1, (const void *)buffer, *count);
				*count = 0;
			}
		}
	}
}
