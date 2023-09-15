#include "main.h"

/**
 * int_format_handler - print signed decimal integers
 * (%i: used for input from scanf, %d: any inputted int)
 * @num: integer to be printed
 * @count: current count of printed characters
 *
 * Return: nothing
 */

void int_format_handler(int num, int count)
{
	char buffer[20]; /*store digits of interger*/
	int j, i = 0;

	if (num == 0) /*simply print 0 and increment*/
	{
		our_ptchar('0');
		count++;
		return;
	}

	if (num < 0) /*handle negatives*/
	{
		our_ptchar('-');
		count++;
		num = -num;
	}

	while (num != 0) /*store digits in the buffer */
	{
		buffer[i++] = (num % 10) + '0';
		num /= 10;
	}

	for (j = i - 1; j >= 0; j--)
	{
		our_ptchar(buffer[j]);
		count++;
	}
}
