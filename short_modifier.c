#include "main.h"

/**
 * short_modifier_handler - Handles 'l' length modifier
 * @format: A pointer to the format string
 * @ap: Argument pointer
 * @count: A pointer to the count of characters in buffer
 * @total: The total number of characters printed
 * @buffer: A pointer to the buffer storing characters to be printed
 */
void short_modifier_handler(const char *format, va_list ap, int *count,
		int *total, char *buffer)
{
	short short_int;
	unsigned short u_short;

	format++;
	switch (*format)
	{
	case 'i':
	case 'd':
		short_int = (short)va_arg(ap, int);
		short_int_handler(short_int, count, total, buffer);
		break;
	case 'u':
		u_short = (unsigned short)va_arg(ap, unsigned int);
		short_u_handler(u_short, count, total, buffer);
		break;
	case 'o':
		u_short = (unsigned short)va_arg(ap, unsigned int);
		short_o_handler(u_short, count, total, buffer);
		break;
	case 'x':
		u_short = (unsigned short)va_arg(ap, unsigned int);
		short_x_handler(u_short, count, total, buffer);
		break;
	case 'X':
		u_short = (unsigned short)va_arg(ap, unsigned int);
		short_upper_x_handler(u_short, count, total, buffer);
		break;
	default:
		exit(1);
	}
	format++;
}
