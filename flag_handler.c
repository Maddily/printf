#include "main.h"

/**
 * flag_handler - handles the implementation of each flag
 * @format: A pointer to the format string
 * @ap: Argument pointer
 * @count: A pointer to the number of characters added to the buffer
 * @total: A pointer to the number of characters printed
 * @buffer: A pointer to the buffer storing characters
 * Return: 0 on success, 1 on error
 */

int flag_handler(const char *format, va_list ap, int *count,
		int *total, char *buffer)
{
	if (*format == '+')
		f_plus_handler(format, ap, count, total, buffer), format++;
	else if (*format == ' ')
		f_space_handler(format, ap, count, total, buffer), format++;
	else if (*format == '#')
		f_hash_handler(format, ap, count, total, buffer), format++;
	else if (*format == '-')
		f_minus_handler(format, ap, count, total, buffer), format++;
	else if (*format == '0')
		f_zero_handler(format, ap, count, total, buffer), format++;
	else
		return (1);

	return (0);
}
