#include "main.h"


/**
 * handle_all - Handles the format string if it isn't NULL
 * @format: A pointer to the format string
 * @ap: Argument pointer
 * @count: A pointer to the number of characters added to the buffer
 * @total: A pointer to the number of characters printed
 * @buffer: A pointer to the buffer storing characters
 * @spec: A pointer to an array of structures
 * Return: 0 on success, -1 on failure
 */
int handle_all(const char *format, va_list ap, int *count, int *total,
		char *buffer, fmt_spec *spec)
{
	int ret, field_width = 0;

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
				percent_handler(count, total, buffer);
			else if (*format == 'l')
			{
				long_modifier_handler(format, ap, count, total, buffer);
				format++;
			}
			else if (*format == 'h')
			{
				short_modifier_handler(format, ap, count, total, buffer);
				format++;
			}
			else if ((*format >= '1' && *format <= '9') || *format == '*')
			{
				if (*format >= '1' && *format <= '9')
				{
					while (*format >= '0' && *format <= '9')
						field_width = (field_width * 10) + (*format - '0');
					format++;
				}
				else if (*format == '*')
				{
					field_width = va_arg(ap, int);
					format++;
				}
				handle_struct(format, spec, ap, count, total, buffer, field_width);
				field_width = 0;
			}
			else
			{
				ret = handle_struct(format, spec, ap, count, total, buffer, field_width);
				if (ret == -1)
					return (-1);
			}
		}
		else
		{
			fill_buffer(format, count, total, buffer);
		}
		format++;
	}
	if (ret == -1)
		return (-1);
	if (*count > 0)
	{
		*total += write(1, (const void *)buffer, *count);
		*count = 0;
	}
	return (0);
}
