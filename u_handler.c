#include "main.h"

/**
 * u_format_handler - handles 'u' specifier
 * @number: unsigned int
 * @count: number of characters printed
 *
 * Return: nothing
 */

void u_format_handler(unsigned int number, int count)
{
	unsigned int temp = number, divisor = 1;

	while (temp / 10 != 0) /*find divisor to get each digit*/
	{
		divisor *= 10;
		temp /= 10;
	}

	while (divisor != 0) /*print each digit*/
	{
		our_ptchar((number / divisor) + '0');
		number %= divisor;
		divisor /= 10;
		count++;
	}
}
