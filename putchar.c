#include "main.h"

/**
 * our_putchar - writes a character to STDOUT
 * for flag use
 * @c: character
 *
 * Return: 0 on success
 */
int our_putchar(char c)
{
	return (write(1, &c, 1));
}
