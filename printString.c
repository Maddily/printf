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
	char buffer[1024];
	int bufferIndex = 0;
	char *input = (string != NULL) ? string : null;

	len = find_length(input);

	for (i = 0; i < len; i++)
	{
		if (input[i] < 32 || input[i] >= 127)
		{
			buffer[bufferIndex++] = '\\';
			buffer[bufferIndex++] = 'x';
			buffer[bufferIndex++] = (input[i] >> 4) + '0';
			buffer[bufferIndex++] = (input[i] & 0xF) + '0';
			count += 4;
		}
		else
		{
			buffer[bufferIndex++] = input[i];
			count += 1;
		}

		if (bufferIndex == 1024 || i == len - 1)
		{
			write(STDOUT_FILENO, buffer, bufferIndex);
			bufferIndex = 0;
		}
	}
}
