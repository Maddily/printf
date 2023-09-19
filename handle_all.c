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
	int ret, field_width = 0, precision = 0;

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
				percent_handler(count, total, buffer);
			else if (*format == '+' || *format == ' ' || *format == '#')
				flag_handler(format, ap, count, total, buffer), format++;
			else if (*format == 'l')
				long_modifier_handler(format, ap, count, total, buffer), format++;
			else if (*format == 'h')
				short_modifier_handler(format, ap, count, total, buffer), format++;
			else if ((*format >= '1' && *format <= '9') || *format == '*')
			{
				if (*format >= '1' && *format <= '9')
				{
					while (*format >= '0' && *format <= '9')
						field_width = (field_width * 10) + (*format - '0'), format++; }
				else if (*format == '*')
					field_width = va_arg(ap, int), format++;
				handle_struct(format, spec, ap, count, total, buffer, field_width);
				field_width = 0; }
			else if (*format == '.')
			{
				format++, ret = precision_handler(format, precision, ap, buffer,
						count, total), format++; }
			else
				ret = handle_struct(format, spec, ap, count, total, buffer, field_width);
			if (ret == -1)
				return (-1); }
		else
			fill_buffer(format, count, total, buffer);
		format++;
	}
	if (ret == -1)
		return (-1);
	if (*count > 0)
		*total += write(1, (const void *)buffer, *count);
	return (0);
}

/**
 * precision_handler - Handles the precision
 * @format: A pointer to the format string
 * @precision: The precision value
 * @ap: Argument pointer
 * @buffer: A pointer to the buffer storing characters
 * @count: A pointer to the number of characters added to the buffer
 * @total: A pointer to the number of characters printed
 * Return: 0 on success, -1 on failure
 */
int precision_handler(const char *format, int precision, va_list ap,
		char *buffer, int *count, int *total)
{
	int i, len;
	char *string;

	if (*format == '*')
	{
		precision = va_arg(ap, int);
		format++;
	}
	else if (*format >= '1' && *format <= '9')
	{
		while (*format >= '0' && *format <= '9')
		{
			precision = (precision * 10) + (*format - '0');
			format++;
		}
	}
	if (*format == 's')
	{
		string = va_arg(ap, char *);
		if (string == NULL)
			string = "(null)";

		len = find_length(string);
		if (precision > len)
			for (i = 0; i < len; i++)
			{
				buffer[(*count)++] = string[i];
				buffer_status_handler(count, total, buffer);
			}
		else
			for (i = 0; i < precision; i++)
			{
				buffer[(*count)++] = string[i];
				buffer_status_handler(count, total, buffer);
			}
	}
	else
		return (-1);
	return (0);
}
