#include "main.c"

/**
 * print_S - prints the string
 * @string: characters provided
 * @count: number of printed characters
 * @len: length of string provided
 * @null: pointer to "(NULL)"
 *
 * Return: nothing
 */

void print_S(char *string, int count, int len, char *null)
{
	if (string != NULL)
	{
		len = find_length(string);
		write(1, string, len);
		*count += len;
	}
	else
	{
		len = find_length(null);
		write(1, null, len);
		*count += len;
	}
}
