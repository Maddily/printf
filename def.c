#include "main.h"

/**
 * default_handler - Handles the %% and prints '%'
 * @character: The character provided as an argument
 * @format: A pointer to the format string
 * @count: The number of printed characters
 */
void default_handler(char character, const char *format, int count)
{
	character = '%';
	write(1, &character, 1);
	write(1, format + 1, 1);
	format++;
	count += 2;
}
