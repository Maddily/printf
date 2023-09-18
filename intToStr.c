#include "main.h"
#include <stdlib.h>

/**
 * intToStr - converts integer to string
 * @num: number
 * Return: string
 */

char* intToString(int num)
{
	int length = 0;
	int temp = num;
	int digit;
	char* str;
	int index = 0;

	while (temp != 0)
	{
		length++;
		temp /= 10;
	}

	str = (char*)malloc((length + 1) * sizeof(char));

	while (num != 0)
	{
		digit = num % 10;
		str[index] = digit + '0';
		index++;
		num /= 10;
	}

	str[index] = '\0';

	return (str);
}
