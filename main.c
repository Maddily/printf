#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 * Return: Always 0
 */

int main(void)
{
	int len;
	int len2;
	int num = 42;
	unsigned int ui;
	void *addr;
	long l_num = 1000000;
	short h_num = 100;

	len = _printf("Let's try to printf a simple sentence.\n");
	len2 = printf("Let's try to printf a simple sentence.\n");
	ui = (unsigned int)INT_MAX + 1024;
	addr = (void *)0x7ffe637541f0;
	_printf("Length:[%d, %i]\n", len, len);
	printf("Length:[%d, %i]\n", len2, len2);
	_printf("Length:[%ld, %li]\n", l_num, l_num);
	printf("Length:[%ld, %li]\n", l_num, l_num);
	_printf("Length:[%hd, %hi]\n", h_num, h_num);
	printf("Length:[%hd, %hi]\n", h_num, h_num);
	_printf("Negative:[%d]\n", -762534);
	printf("Negative:[%d]\n", -762534);
	_printf("Unsigned:[%u]\n", ui);
	printf("Unsigned:[%u]\n", ui);
	_printf("Unsigned:[%hu]\n", h_num);
	printf("Unsigned:[%hu]\n", h_num);
	_printf("Unsigned octal:[%o]\n", ui);
	printf("Unsigned octal:[%o]\n", ui);
	_printf("Unsigned octal:[%ho]\n", ui);
	printf("Unsigned octal:[%ho]\n", ui);
	_printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	_printf("Unsigned hexadecimal:[%hx, %hX]\n", ui, ui);
	printf("Unsigned hexadecimal:[%hx, %hX]\n", ui, ui);
	_printf("Character:[%c]\n", 'H');
	printf("Character:[%c]\n", 'H');
	_printf("String:[%s]\n", "I am a string !");
	printf("String:[%s]\n", "I am a string !");
	_printf("Address:[%p]\n", addr);
	printf("Address:[%p]\n", addr);
	len = _printf("Percent:[%%]\n");
	len2 = printf("Percent:[%%]\n");
	_printf("Len:[%d]\n", len);
	printf("Len:[%d]\n", len2);
	_printf("%S\n", "Best\nSchool");
	return (0);
}
