#include "main.h"

/**
 * trailing_percent_error - Prints an error and exits if there's a %
 * at the end of the format string.
 * @format: A pointer to the format string
 */
void trailing_percent_error(const char *format)
{
	int format_len = find_const_length(format);

	if (format[format_len - 1] == '%')
	{
		exit(1);
	}

}
