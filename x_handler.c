#include "main.h"

/**
 * printUpperHex - prints uppercase hexadecimal integers
 * @number: unsigned int
 * @count: current count of printed characters
 *
 * Return: nothing
 */

void printUpperHex(unsigned int number, int count)
{
	char hexaDigits[] = "0123456789ABCDEF";
	char hexaNumber[10];
	int i, remainder;

	count = 0;

	if (number == 0) /*check if o*/
	{
		our_ptchar('0');
		return;
	}

	while (number > 0) /*convert number to hex*/
	{
		remainder = number % 16;
		hexaNumber[count++] = hexaDigits[remainder];
		number /= 16;
	}

	for (i = count - 1; i >= 0; i--)
		our_ptchar(hexaNumber[i]);

}
