#include "main.h"

/**
 * flag_handler - handles flag characters
 * listed +, space, -, 0, #
 * @format: A pointer to the format string
 * @ap: Argument pointer
 * @count: A pointer to the count of characters in buffer
 * @total: The total number of characters printed
 * @buffer: A pointer to the buffer storing characters to be printed
 */

void flag_handler(const char* format, va_list ap, int* count, int* total, char* buffer)
{
	switch (*format)
	{
		case '+':
			handle_plus_flag(ap, count, total, buffer);
			break;
		case ' ':
			handle_space_flag(ap, count, total, buffer);
			break;
		case '#':
			handle_hash_flag(ap, count, total, buffer);
			break;
		default:
			break;
	}
}
