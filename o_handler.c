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
	int k;

	count = 0;

	while (number != 0)
	{
		octal[count++] = '0' + (number % 8);
		number /= 8;
	}
	octal[count] = '\0';

	for (k = count - 1; k >= 0; k--)
		our_ptchar(octal[k]);
}
