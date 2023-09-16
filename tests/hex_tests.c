#include "main.h"

/**
 * main - Entry point
 * Return: Always 0
 */

int main(void)
{
	unsigned int ui = 447;

	printf("Hexadecimal (lowercase): %x\n", ui);
	_printf("Hexadecimal (lowercase): %x\n", ui);
	printf("Hexadecimal (uppercase): %X\n", ui);
	_printf("Hexadecimal (uppercase): %X\n", ui);
	return (0);
}
