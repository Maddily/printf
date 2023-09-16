#include "main.h"

/**
 * print_S - prints the string
 * (non printable characters displayed as /x, followed
 * by ASCII code value in hexadecimal)
 *
 * @string: characters provided
 * @count: number of printed characters
 * @len: length of string provided
 * @null: pointer to "(NULL)"
 *
 * Return: nothing
 */

void print_S(char *string, int count, int len, char *null)
{
	int i = 0;
	char *input = (string != NULL) ? string : null;


	len = find_length(input);

	for (i = 0; i < len; i++)
	{
		if (input[i] < 32 || input[i] >= 127)
		{
			our_ptchar('\\');
			our_ptchar('x');
			our_ptchar((input[i] >> 4) + '0');
			our_ptchar((input[i] & 0xF) + '0');
			count += 4;
		}
		else
		{
			our_ptchar(input[i]);
			count += 1;
		}
	}
}
