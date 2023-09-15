#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
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

/**
 * _printf - Produces output according to a format
 * @format: A character string composed of zero or more directives
 * Return: The number of characters printed
 * (excluding the null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
	va_list ap;
	char character = ' ', *null = "(null)", *string;
	int len, count;

	if (format != NULL)
	{
		va_start(ap, format), count = 0;
		while (*format)
		{
			if (*format == '%')
				switch (*(format + 1))
				{
				case 'c':
					char_format_handler
						(ap, character, count);
					format++;
					break;
				case 's':
					string = va_arg(ap, char *);
					str_format_handler(string, count, len, null);
					format++;
					break;
				case '%':
					percent_handler(character, count);
					format++;
					break;
				case 'd':
				case 'i':
					int_format_handler(va_arg(ap, int), count);
					format++;
					break;
				case 'u':
					u_format_handler(va_arg(ap, unsigned int), count);
					format++;
					break;
				case 'b':
					custom_b_handler(ap, count);
					format++;
					break;
				default:
					default_handler(character, format, count);
					format++;
				}
			else
				write(1, format, 1), count++;
			format++;
			len = 0;
		}
	}
	va_end(ap);
	return (count);
}
