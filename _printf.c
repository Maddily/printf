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
	fmt_spec specs[] = {
		{'c', char_format_handler},
		{'s', str_format_handler},
		{'d', int_format_handler},
		{'i', int_format_handler},
		{'u', u_format_handler},
		{'o', o_format_handler},
		{'x', x_format_handler},
		{'X', printUpperHex},
		{'p', ptr_format_handler},
		{'b', custom_b_handler},
		{'S', custom_S_handler},
		{'0', NULL}
	};
	va_list ap;
	char buffer[1024];
	int count = 0, total = 0;
	fmt_spec *spec = specs;

	trailing_percent_error(format);
	if (format != NULL)
	{
		va_start(ap, format);
		/*Handle format specifiers, add to the buffer and print*/
		handle_all(format, ap, &count, &total, buffer, spec);
	}
	else
		return (1);
	va_end(ap);
	return (total);
}
