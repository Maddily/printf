#include "main.h"

/**
 * o_format_handler - prints an unsigned octal integer
 * @number: unsigned octal
 * @count: number of characters printed
 *
 * Return: nothing
 */

void o_format_handler(unsigned int number, int count)
{
	char octal[32];
	char buffer[1024];
	int k;
	int buffer_index = 0;;

	count = 0;

	while (number != 0)
	{
		octal[count++] = '0' + (number % 8);
		number /= 8;
	}
	octal[count] = '\0';

	for (k = count - 1; k >= 0; k--)
	{
		buffer[buffer_index++] = octal[k];

		if (buffer_index == 1024 || k == 0)
		{
			write(1, buffer, buffer_index);
			buffer_index = 0;
		}
	}
}
