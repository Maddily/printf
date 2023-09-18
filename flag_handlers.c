#include "main.h"

/*------flag handling for 0, space, plus, minus and hash ------ */

/**
 * handle_space_flag - add a space character before positive numbers
 * @format: A pointer to the format string
 * @ap: Argument pointer
 * @count: A pointer to the count of characters in buffer
 * @total: The total number of characters printed
 * @buffer: A pointer to the buffer storing characters to be printed
 */

void handle_space_flag(va_list ap, int* count, int* total, char* buffer)
{
	int number = va_arg(ap, int);
	int i;
	char* str;
	int length;

	if (number >= 0)
	{
		str = intToString(number);
		length = find_length(str);

		for (i = 1; i < length; i++)
		{
			buffer[*count] = ' ';
			(*count)++;
			(*total)++;
		}

		for (i = length - 1; i >= 0; i--)
		{
			buffer[*count] = str[i];
			(*count)++;
			(*total)++;
		}
		free(str);
	}
}

/**
 * handle_plus_flag - add a plus sign before positive numbers
 * @format: A pointer to the format string
 * @ap: Argument pointer
 * @count: A pointer to the count of characters in buffer
 * @total: The total number of characters printed
 * @buffer: A pointer to the buffer storing characters to be printed
 */

void handle_plus_flag(va_list ap, int* count, int* total, char* buffer)
{
	int number = va_arg(ap, int);
	int length, i;
	char* str;

	if (number >= 0)
	{
		str = intToString(number);
		length = find_length(str);

		for (i = 1; i < length; i++)
		{
			buffer[*count] = '+';
			(*count)++;
			(*total)++;
		}

		for (i = length - 1; i >= 0; i--)
		{
			buffer[*count] = str[i];
			(*count)++;
			(*total)++;
		}
		free(str);
	}
}

/**
 * handle_hash_flag - add a prefix or suffix
 * @format: A pointer to the format string
 * @ap: Argument pointer
 * @count: A pointer to the count of characters in buffer
 * @total: The total number of characters printed
 * @buffer: A pointer to the buffer storing characters to be printed
 */

void handle_hash_flag(va_list ap, int* count, int* total, char* buffer)
{
	int num = va_arg(ap, int);
	char hex[9], temp;
	int i, j, len, rem;

	i = 0; /*To do: create function that will convert num to hex*/
	while (num != 0)
	{
		rem = num % 16;
		if (rem < 10)
			hex[i] = rem + '0';
		else
			hex[i] = rem - 10 + 'a';
		num /= 16;
		i++;
	}
	hex[i] = '\0';

	len = find_length(hex); /*To do: create function taht reverses hex string*/
	for (j = 0; j < len / 2; j++)
	{
		temp = hex[j];
		hex[j] = hex[len - j - 1];
		hex[len - j - 1] = temp;
	}

	buffer[*count] = '0'; /* Add the prefix "0x" to the buffer*/
	buffer[*count + 1] = 'x';
	for (j = 0; j < len; j++)
		buffer[*count + j + 2] = hex[j];

	*count += len + 2;
	*total += len + 2;
}
