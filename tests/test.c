#include <stdio.h>
#include "main.h"

int main(void)
{
	printf("The %s se%ason %% is nice :%c\n", "Autumn", ')');
	_printf("The %s se%ason %% is nice :%c\n", "Autumn", ')');

	printf("Hello world %c %c\n", 'o', "oo");
	_printf("Hello world %c %c\n",'o', "oo");

	printf("Hello world %c %s\n", 'o');
	_printf("Hello world %c %s\n",'o');

	return (0);
}
