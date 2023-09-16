#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "main.h"

/**
 * _printf - Produces output according to a format
 * @format: A character string composed of zero or more directives
 * Return: The number of characters printed
 * (excluding the null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
	va_list ap;
	char *string, buffer[1024];
	int count = 0, total = 0;

	trailing_percent_error(format);
	if (format != NULL)
	{
		va_start(ap, format);
		while (*format)
		{
			if (*format == '%')
			{
				format++;
				switch (*format)
				{
				case 'c':
					char_format_handler
						(ap, &count, &total, buffer);
					break;
				case 's':
					string = va_arg(ap, char *);
					str_format_handler(string, &count, &total, buffer);
					break;
				case '%':
					percent_handler(&count, &total, buffer);
					break;
				case 'd':
				case 'i':
					int_format_handler(va_arg(ap, int), &count, &total, buffer);
					break;
				case 'u':
					u_format_handler(va_arg(ap, unsigned int), count);
					format++;
					break;
				case 'o':
					o_format_handler(va_arg(ap, unsigned int), count);
					format++;
					break;
				case 'x':
					x_format_handler(va_arg(ap, unsigned int), count);
					format++;
					break;
				case 'X':
					printUpperHex(va_arg(ap, unsigned int), count);
					format++;
					break;
				case 'b':
					custom_b_handler(ap, &count, &total, buffer);
					break;
				default:
					default_handler(format, &count, &total, buffer);

				}
			}
			else
			{
				buffer[count++] = *format;

				if (count == 1024)
				{
					total += write(1, (const void *)buffer, count);
					count = 0;
				}
			}
			format++;
		}
		if (count > 0)
		{
			total += write(1, (const void *)buffer, count);
		}
	}
	va_end(ap);
	return (total);
}
