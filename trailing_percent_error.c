#include "main.h"

/**
 * trailing_percent_error - Prints an error and exits if there's a %
 * at the end of the format string.
 */
void trailing_percent_error(const char *format)
{
	int format_len = find_const_length(format);
	char *error = "error: spurious trailing ‘%’ in format\n";
	int error_len = find_length(error);

	if (format[format_len - 1] == '%')
	{
		write(2, error, error_len);
		exit(1);
	}

}
