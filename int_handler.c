#include "main.h"

/**
 * int_format_handler - print signed decimal integers
 * (%i: used for input from scanf, %d: any inputted int)
 * @ap: Argument pointer
 * @count: A pointer to the current count of printed characters
 * @total: A pointer to the total number of characters printed
 * @buffer: A pointer to the buffer holding the characters to be printed
 * Return: nothing
 */

void int_format_handler(va_list ap, int *count, int *total, char *buffer)
{
	char int_buffer[20]; /*store digits of interger*/
	int j, i = 0;
	int number = va_arg(ap, int);

	if (number == 0) /*Add '0' to the buffer*/
	{
		handle_zero_number(count, total, buffer);
		return;
	}

	if (number < 0) /*handle negatives*/
	{
		buffer[*count] = '-';
		(*count)++;

		if (*count == 1024)
		{
			*total += write(1, (const void *)buffer, *count);
			*count = 0;
		}
		number = -number;
	}

	if (number == INT_MIN) /* handle INT_MIN separately */
	{
		int_buffer[i++] = '8';
		number = 214748364;
	}

	while (number != 0) /*store digits in int_buffer */
	{
		int_buffer[i++] = (number % 10) + '0';
		number /= 10;
	}

	for (j = i - 1; j >= 0; j--) /*Add int_buffer's contents to buffer*/
	{
		buffer[*count] = int_buffer[j];
		(*count)++;

		if (*count == 1024)
		{
			*total += write(1, (const void *)buffer, *count);
			*count = 0;
		}
	}
}
