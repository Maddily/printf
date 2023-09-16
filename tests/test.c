#include <stdio.h>
#include "main.h"

int main(void)
{
	printf("%s %% is nice :%c\n", "Autumn", ')');
	_printf("%s %% is nice :%c\n", "Autumn", ')');

	/* printf("Hello world %c %c%", 'o', 'm'); */
	_printf("Hello world %c %c%",'o', 'm');

	/* printf("Hello world %c %s\n", 'o'); */
	/* _printf("Hello world %c %s\n",'o'); */

	return (0);
}
