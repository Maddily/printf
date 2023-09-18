#include "main.h"

/**
 * long_int_handler - print signed decimal integers
 * (%i: used for input from scanf, %d: any inputted int)
 * @number: integer to be printed
 * @count: A pointer to the current count of printed characters
 * @total: A pointer to the total number of characters printed
 * @buffer: A pointer to the buffer holding the characters to be printed
 * Return: nothing
 */
void long_int_handler(long number, int *count, int *total, char *buffer)
{
	char int_buffer[20]; /*store digits of interger*/
	int j, i = 0;

	if (number == 0) /*Add '0' to the buffer*/
	{
		handle_zero_number(count, total, buffer);
		return;
	}
	if (number < 0) /*handle negatives*/
	{
		buffer[*count] = '-';
		(*count)++;

		if (*count == 1024)
		{
			*total += write(1, (const void *)buffer, *count);
			*count = 0;
		}
		number = -number;
	}
	while (number != 0) /*store digits in int_buffer */
	{
		int_buffer[i++] = (number % 10) + '0';
		number /= 10;
	}
	for (j = i - 1; j >= 0; j--) /*Add int_buffer's contents to buffer*/
	{
		buffer[*count] = int_buffer[j];
		(*count)++;

		if (*count == 1024)
		{
			*total += write(1, (const void *)buffer, *count);
			*count = 0;
		}
	}
}

/**
 * long_o_handler - prints an unsigned octal integer
 * @number: unsigned octal
 * @count: number of characters printed
 * @total: A pointer to the total number of characters printed
 * @buffer: A pointer to the buffer holding the characters to be printed
 *
 * Return: nothing
 */
void long_o_handler(unsigned long number, int *count,
		int *total, char *buffer)
{
	char octal_buffer[32];
	int k, i = 0;

	if (number == 0)
	{
		buffer[*count] = '0';
		(*count)++;

		if (*count == 1024)
		{
			*total += write(1, (const void *)buffer, *count);
			*count = 0;
		}
		return;
	}

	while (number != 0)
	{
		octal_buffer[i++] = '0' + (number % 8);
		number /= 8;
	}

	for (k = i - 1; k >= 0 && *total < 1024; k--)
	{
		buffer[*count] = octal_buffer[k];
		(*count)++;

		if (*count == 1024)
		{
			*total += write(1, (const void *)buffer, *count);
			*count = 0;
		}
	}
}

/**
 * long_u_handler - handles 'u' specifier
 * @number: unsigned int
 * @count: number of characters printed
 * @total: A pointer to the total number of characters printed
 * @buffer: A pointer to the buffer holding the characters to be printed
 *
 * Return: nothing
 */
void long_u_handler(unsigned long number, int *count,
		int *total, char *buffer)
{
	char decimal_buffer[32];
	int m, i = 0;

	if (number == 0)
	{
		handle_zero_number(count, total, buffer);
		return;
	}

	while (number != 0)
	{
		decimal_buffer[i++] = '0' + (number % 10);
		number /= 10;
	}

	for (m = i - 1; m >= 0 && *total < 1024; m--)
	{
		buffer[*count] = decimal_buffer[m];
		(*count)++;

		if (*count == 1024)
		{
			*total += write(1, (const void *)buffer, *count);
			*count = 0;
		}
	}
}

/**
 * long_upper_x_handler - prints uppercase hexadecimal integers
 * @number: unsigned int
 * @count: current count of printed characters
 * @total: A pointer to the total number of characters printed
 * @buffer: A pointer to the buffer holding the characters to be printed
 *
 * Return: nothing
 */
void long_upper_x_handler(unsigned long number, int *count,
		int *total, char *buffer)
{
	char hex_buffer[32];
	int i = 0, remainder, h;

	if (number == 0) /*check if o*/
	{
		buffer[*count] = '0';
		(*count)++;

		if (*count == 1024)
		{
			*total += write(1, (const void *)buffer, *count);
			*count = 0;
		}
		return;
	}

	while (number != 0) /*convert number to upper hex*/
	{
		remainder = number % 16;
		if (remainder < 10)
			hex_buffer[i++] = '0' + remainder;
		else
			hex_buffer[i++] = 'A' + (remainder - 10);
		number /= 16;
	}

	for (h = i - 1; h >= 0 && *total < 1024; h--)
	{
		buffer[*count] = hex_buffer[h];
		(*count)++;

		if (*count == 1024)
		{
			*total += write(1, (const void *)buffer, *count);
			*count = 0;
		}
	}
}

/**
 * long_x_handler - prints lowercase hexadecimal integers
 * @number: unsigned int
 * @count: current count of printed characters
 * @total: A pointer to the total number of characters printed
 * @buffer: A pointer to the buffer holding the characters to be printed
 *
 * Return: nothing
 */
void long_x_handler(unsigned long number, int *count,
		int *total, char *buffer)
{
	char hex_buffer[32];
	int i = 0, remainder, k;

	if (number == 0)
	{
		buffer[*count] = '0';
		(*count)++;

		if (*count == 1024)
		{
			*total += write(1, (const void *)buffer, *count);
			*count = 0;
		}
		return;
	}

	while (number != 0)
	{
		remainder = number % 16;
		if (remainder < 10)
			hex_buffer[i++] = '0' + remainder;
		else
			hex_buffer[i++] = 'a' + (remainder - 10);
		number /= 16;
	}

	for (k = i - 1; k >= 0 && *total < 1024; k--)
	{
		buffer[*count] = hex_buffer[k];
		(*count)++;

		if (*count == 1024)
		{
			*total += write(1, (const void *)buffer, *count);
			*count = 0;
		}
	}
}
