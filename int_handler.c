#include "main.h"

/**
 * int_format_handler - print signed decimal integers
 * (%i: used for input from scanf, %d: any inputted int)
 * @number: integer to be printed
 * @count: current count of printed characters
 *
 * Return: nothing
 */

void int_format_handler(int number, int count)
{
	char buffer[20]; /*store digits of interger*/
	int j, i = 0;

	if (number == 0) /*simply print 0 and increment*/
	{
		our_ptchar('0');
		count++;
		return;
	}

	if (number < 0) /*handle negatives*/
	{
		our_ptchar('-');
		count++;
		number = -number;
	}

	while (number != 0) /*store digits in the buffer */
	{
		buffer[i++] = (number % 10) + '0';
		number /= 10;
	}

	for (j = i - 1; j >= 0; j--)
	{
		our_ptchar(buffer[j]);
		count++;
	}
}
