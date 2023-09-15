#include <stdio.h>
#include "main.h"

/* --- test files for %i and %d (task 1) ---*/

int main(void)
{
	int num1 = 40, num2 = -30, num3 = 5, num4 = 1.5;
	unsigned int number = 42;

	printf("The sum of 40 and -30 is equal to %i.\n", (num1 + num2));
	_printf("The sum of 40 and -30 is equal to %i.\n", (num1 + num2));
	printf("The sum of -30 and 5 is equal to %i.\n", (num2 + num3));
	_printf("The sum of -30 and 5 is equal to %i.\n", (num2 + num3));
	printf("The sum of 40 and 1.5 is equal to %d.\n", (num1 + num4));
	_printf("The sum of 40 and 1.5 is equal to %d.\n", (num1 + num4));
	printf("The unsigned number is: %u\n", number);
	_printf("The unsigned number is: %u\n", number);
	return (0);
}
