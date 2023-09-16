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

	if (string != NULL)
	{
		len = find_length(string);
		for (i = 0; i < len; i++)
		{
			if (string[i] < 32 || string[i] >= 127)
			{
				our_ptchar('\\');
				our_ptchar('x');
				our_ptchar((string[i] >> 4) + '0');
				our_ptchar((string[i] & 0xF) + '0');
				count += 4;
			}
			else
			{
				our_ptchar(string[i]);
				count += 1;
			}
		}
	}
	else
	{
		len = find_length(null);
		for (i = 0; i < len; i++)
		{
			if (null[i] < 32 || null[i] >= 127)
			{
				our_ptchar('\\');
				our_ptchar('x');
				our_ptchar((null[i] >> 4) + '0');
				our_ptchar((null[i] & 0xF) + '0');
				count += 4;
			}
			else
			{
				our_ptchar(null[i]);
				count += 1;
			}
		}
	}
}
