#include "main.h"
#include <stdlib.h>

/**
 * my_itoa - converts digit to character
 * @buffer: buffer
 * @num: digit to be converted
 * @format: format
 * @base: base of digit
 * Return: always 0
 */

int my_itoa(const char *format, char *buffer, int num, int base)
{
	int digit, len, temp, original_len;

	if (buffer == NULL)
		return (0);
	temp = num;
	len = 0;
	if (num == 0)
	{
		buffer[0] = '0';
		buffer[1] = '\0';
		return (1);
	}
	if (num < 0)
	{
		num = -num;
		buffer[0] = '-';
		len++;
	}
	while (temp != 0)
	{
		temp /= base;
		len++;
	}
	original_len = len;
	buffer[len] = '\0';
	while (num != 0)
	{
		digit = num % base;
		if (digit > 9)
		{
			if (format[1] == 'X')
				buffer[len - 1] = 'A' + digit - 10;
			else
				buffer[len - 1] = 'a' + digit - 10; }
		else
			buffer[len - 1] = '0' + digit;
		num /= base;
		len--; }
	return (original_len);
}

