#include "main.h"

/**
 * handle_struct - Loops through the array of structs
 * @format: A pointer to the format string
 * @spec: A pointer to an array of structures
 * @ap: Argument pointer
 * @count: A pointer to the number of characters added to the buffer
 * @total: A pointer to the number of characters printed
 * @buffer: A pointer to the buffer storing characters
 * @field_width: The field width
 * Return: 0 on success, -1 on failure
 */
int handle_struct(const char *format, fmt_spec *spec, va_list ap, int *count,
		int *total, char *buffer, int field_width)
{
	while (spec->spec != '0')
	{
		if (spec->spec == *format)
		{
			spec->hndlr(ap, count, total, buffer, field_width);
			return (0);
		}
		spec++;
	}

	return (-1);
}
