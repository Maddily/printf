#include "main.h"

/**
 * custom_b_handler - Handles a custom %b format specifier
 * Description: The %b format specifier coverts an unsigned int argument
 * to binary
 * @ap: Argument pointer
 * @count: The number of printed characters
 */
void custom_b_handler(va_list ap, int count)
{
	unsigned int number;
	char bin[CHAR_BIT * sizeof(unsigned int)];
	int i, j;

	number = va_arg(ap, unsigned int);
	if (number == 0)
	{
		our_ptchar('0');
		count++;
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
			our_ptchar(bin[j]);
			count++;
		}
	}
}
