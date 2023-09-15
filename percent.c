#include "main.h"

/**
 * percent_handler - Handles the %% and prints '%'
 * @character: The character provided as an argument
 * @count: The number of printed characters
 */
void percent_handler(char character, int count)
{
	character = '%';
	write(1, &character, 1);
	count++;
}
