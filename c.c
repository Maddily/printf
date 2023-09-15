#include "main.h"

/**
 * char_format_handler - Handles the %c format specifier and
 * prints the argument corresponding to it
 * @ap: Argument pointer
 * @character: The character provided as an argument
 * @count: The number of printed characters
 */
void char_format_handler(va_list ap, char character, int count)
{
	character = (char)va_arg(ap, int);
	if (character != '\0')
	{
		write(1, &character, 1);
		count++;
	}
}
