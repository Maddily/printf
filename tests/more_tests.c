#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 * Return: Always 0
 */

int main(void)
{
	int num = 42;
	unsigned int ui;
	void *addr;

	ui = (unsigned int)INT_MAX + 1024;
	addr = (void *)0x7ffe637541f0;

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
	return (0);
}
