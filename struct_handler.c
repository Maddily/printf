#include "main.h"

/**
 * handle_struct - Loops through the array of structs
 * @format: A pointer to the format string
 * @spec: A pointer to an array of structures
 * @ap: Argument pointer
 * @count: A pointer to the number of characters added to the buffer
 * @total: A pointer to the number of characters printed
 * @buffer: A pointer to the buffer storing characters
 */
void handle_struct(const char *format, fmt_spec *spec, va_list ap, int *count,
		int *total, char *buffer)
{
	while (spec->spec != '0')
	{
		if (spec->spec == *format)
		{
			spec->hndlr(ap, count, total, buffer);
			break;
		}
		spec++;
	}
	if (spec->spec == '0')
		exit(1);
	format++;
}
