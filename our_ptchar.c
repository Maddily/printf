#include "main.h"

/**
 * our_ptchar - writes a single character to stdout
 * @c: character
 *
 * Return: Always 0
 */

int our_ptchar(char c)
{
	return (write(1, &c, 1));
}
