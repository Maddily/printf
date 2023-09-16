#include "main.h"

/**
 * x_format_handler - prints lowercase hexadecimal integers
 * @number: unsigned int
 * @count: current count of printed characters
 *
 * Return: nothing
 */

void x_format_handler(unsigned int number, int count)
{
	char hexDigits[] = "0123456789abcdef";
	char hexNumber[10];
	int i, remainder;

	count = 0;

	if (number == 0)
	{
		our_ptchar('0');
		return;
	}

	while (number > 0)
	{
		remainder = number % 16;
		hexNumber[count++] = hexDigits[remainder];
		number /= 16;
	}

	for (i = count - 1; i >= 0; i--)
		our_ptchar(hexNumber[i]);
}
