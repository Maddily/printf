#include "main.h"
#include <stdlib.h>

/**
 * my_itoa - converts digit to character
 * @buffer: buffer
 * @num: digit to be converted
 *
 * Return: always 0
 */

int my_itoa(char* buffer, int num)
{
	int digit, len, temp = num;
	int original_len;

	len = 0;

	if (num == 0)
	{
		buffer[0] = '0';
		buffer[1] = '\0';
		return (1);
	}

	while (temp != 0)
	{
		temp /= 10;
		len++;
	}

	original_len = len;

	while (num != 0)
	{
		digit = num % 10;
		buffer[len - 1] = '0' + digit;
		num /= 10;
		len--;
	}
	return (original_len);
}

