#include "main.h"

/**
 * long_modifier_handler - Handles 'l' length modifier
 * @format: A pointer to the format string
 * @ap: Argument pointer
 * @count: A pointer to the count of characters in buffer
 * @total: The total number of characters printed
 * @buffer: A pointer to the buffer storing characters to be printed
 */
void long_modifier_handler(const char *format, va_list ap, int *count,
		int *total, char *buffer)
{
	long long_int;
	unsigned long u_long;

	format++;
	switch (*format)
	{
	case 'i':
	case 'd':
		long_int = va_arg(ap, long);
		long_int_handler(long_int, count, total, buffer);
		break;
	case 'u':
		u_long = va_arg(ap, unsigned long);
		long_u_handler(u_long, count, total, buffer);
		break;
	case 'o':
		u_long = va_arg(ap, unsigned long);
		long_o_handler(u_long, count, total, buffer);
		break;
	case 'x':
		u_long = va_arg(ap, unsigned long);
		long_x_handler(u_long, count, total, buffer);
		break;
	case 'X':
		u_long = va_arg(ap, unsigned long);
		long_upper_x_handler(u_long, count, total, buffer);
		break;
	default:
		default_handler(format, count, total, buffer);
	}
}
