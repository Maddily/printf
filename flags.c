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
	int i;

	FlagHandler flagHandlers[256] = { NULL };

	flagHandlers[' '] = handle_space_flag;
	flagHandlers['+'] = handle_plus_flag;
	flagHandlers['#'] = handle_hash_flag;

	for (i = 0; format[i] != '\0'; i++)
	{
		FlagHandler handler = flagHandlers[(unsigned char)format[i]];
		if (handler != NULL)
		{
			handler(ap, count, total, buffer);
		}
	}
}
