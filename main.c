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
	unsigned long ul;
	void *addr;
	long l_num = 1000000;
	short h_num = 100;

	len = _printf("Let's try to printf a simple sentence.\n");
	len2 = printf("Let's try to printf a simple sentence.\n");
	ui = (unsigned int)INT_MAX + 1024;
	ul = (unsigned long)INT_MAX + 1024;
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
	_printf("Unsigned:[%lu]\n", l_num);
	printf("Unsigned:[%lu]\n", l_num);
	_printf("Unsigned:[%hu]\n", h_num);
	printf("Unsigned:[%hu]\n", h_num);
	_printf("Unsigned octal:[%o]\n", ui);
	printf("Unsigned octal:[%o]\n", ui);
	_printf("Unsigned octal:[%lo]\n", ul);
	printf("Unsigned octal:[%lo]\n", ul);
	_printf("Unsigned octal:[%ho]\n", ui);
	printf("Unsigned octal:[%ho]\n", ui);
	_printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	_printf("Unsigned hexadecimal:[%lx, %lX]\n", ul, ul);
	printf("Unsigned hexadecimal:[%lx, %lX]\n", ul, ul);
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
	_printf("%R\n", "hihihi");
	_printf("%r\n", "hihihi");
	_printf("Field width of 5: %5d\n", num);
	printf("Field width of 5: %5d\n", num);
	_printf("Field width of 5: %*d\n", 5, num);
	printf("Field width of 5: %*d\n", 5, num);
	_printf("Field width of 5: %5c\n", 'M');
	printf("Field width of 5: %5c\n", 'M');
	_printf("Field width of 5: %*c\n", 5, 'M');
	printf("Field width of 5: %*c\n", 5, 'M');
	_printf("Field width of 5: %5s\n", "Hey");
	printf("Field width of 5: %5s\n", "Hey");
	_printf("Field width of 5: %*s\n", 5, "Hey");
	printf("Field width of 5: %*s\n", 5, "Hey");
	_printf("Unsigned:[%15u]\n", ui);
	printf("Unsigned:[%15u]\n", ui);
	_printf("Unsigned:[%*u]\n", 15, ui);
	printf("Unsigned:[%*u]\n", 15, ui);
	_printf("Unsigned hexadecimal:[%10x, %10X]\n", ui, ui);
	printf("Unsigned hexadecimal:[%10x, %10X]\n", ui, ui);
	_printf("Unsigned hexadecimal:[%*x, %*X]\n", 10, ui, 10, ui);
	printf("Unsigned hexadecimal:[%*x, %*X]\n", 10, ui, 10, ui);
	_printf("Unsigned octal:[%15o]\n", ui);
	printf("Unsigned octal:[%15o]\n", ui);
	_printf("Unsigned octal:[%*o]\n", 15, ui);
	printf("Unsigned octal:[%*o]\n", 15, ui);
	_printf("Address:[%15p]\n", addr);
	printf("Address:[%15p]\n", addr);
	_printf("Address:[%*p]\n", 15, addr);
	printf("Address:[%*p]\n", 15, addr);
	_printf("String:[%.4s]\n", "I am a string !");
	printf("String:[%.4s]\n", "I am a string !");
	_printf("String:[%.*s]\n", 4, "I am a string !");
	printf("String:[%.*s]\n", 4, "I am a string !");
	return (0);
}
