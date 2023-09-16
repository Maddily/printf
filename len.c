#include "main.h"

/**
 * find_length - Finds the length of a string
 * @s: A pointer to a string
 * Return: The length of the string s
 */
int find_length(char *s)
{
	int len;

	len = 0;
	while (s[len] != '\0')
		len++;

	return (len);
}
