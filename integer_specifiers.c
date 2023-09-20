#include "main.h"

/**
 * o_format_handler - prints an unsigned octal integer
 * @ap: Argument pointer
 * @count: number of characters printed
 * @total: A pointer to the total number of characters printed
 * @buffer: A pointer to the buffer holding the characters to be printed
 * @field_width: The field width
 * Return: nothing
 */

void o_format_handler(va_list ap, int *count, int *total, char *buffer,
		int field_width)
{
	char octal_buffer[32];
	int k, i = 0;
	unsigned int number = va_arg(ap, unsigned int);

	if (number == 0)
	{
		field_width -= 1;
		field_width_handler(field_width, buffer, count, total);
		buffer[(*count)++] = '0';
		buffer_status_handler(count, total, buffer);
		return;
	}

	while (number != 0)
	{
		octal_buffer[i++] = '0' + (number % 8);
		number /= 8;
	}

	if (field_width > 0)
	{
		field_width -= i;
		field_width_handler(field_width, buffer, count, total);
	}

	for (k = i - 1; k >= 0 && *total < 1024; k--)
	{
		buffer[(*count)++] = octal_buffer[k];
		buffer_status_handler(count, total, buffer);
	}
}

/**
 * u_format_handler - handles 'u' specifier
 * @ap: Argument pointer
 * @count: number of characters printed
 * @total: A pointer to the total number of characters printed
 * @buffer: A pointer to the buffer holding the characters to be printed
 * @field_width: The field width
 * Return: nothing
 */

void u_format_handler(va_list ap, int *count, int *total, char *buffer,
		int field_width)
{
	char decimal_buffer[32];
	int m, i = 0;
	unsigned int number = va_arg(ap, unsigned int);

	if (number == 0)
	{
		field_width -= 1;
		field_width_handler(field_width, buffer, count, total);
		handle_zero_number(count, total, buffer);
		return;
	}
	while (number != 0)
	{
		decimal_buffer[i++] = '0' + (number % 10);
		number /= 10;
	}
	if (field_width > 0)
	{
		field_width -= i;
		field_width_handler(field_width, buffer, count, total);
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
 * printUpperHex - prints uppercase hexadecimal integers
 * @ap: Argument pointer
 * @count: current count of printed characters
 * @total: A pointer to the total number of characters printed
 * @buffer: A pointer to the buffer holding the characters to be printed
 * @field_width: The field width
 * Return: nothing
 */

void printUpperHex(va_list ap, int *count, int *total, char *buffer,
		int field_width)
{
	char hex_buffer[32];
	int i = 0, remainder, h;
	unsigned int number = va_arg(ap, unsigned int);

	if (number == 0) /*check if o*/
	{
		field_width -= 1;
		field_width_handler(field_width, buffer, count, total);
		buffer[(*count)++] = '0';
		buffer_status_handler(count, total, buffer);
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

	if (field_width > 0)
	{
		field_width -= i;
		field_width_handler(field_width, buffer, count, total);
	}

	for (h = i - 1; h >= 0 && *total < 1024; h--)
	{
		buffer[(*count)++] = hex_buffer[h];
		buffer_status_handler(count, total, buffer);
	}
}

/**
 * x_format_handler - prints lowercase hexadecimal integers
 * @ap: Argument pointer
 * @count: current count of printed characters
 * @total: A pointer to the total number of characters printed
 * @buffer: A pointer to the buffer holding the characters to be printed
 * @field_width: The field width
 * Return: nothing
 */

void x_format_handler(va_list ap, int *count, int *total, char *buffer,
		int field_width)
{
	char hex_buffer[32];
	int i = 0, remainder, k;
	unsigned int number = va_arg(ap, unsigned int);

	if (number == 0)
	{
		field_width -= 1;
		field_width_handler(field_width, buffer, count, total);
		buffer[(*count)++] = '0';
		buffer_status_handler(count, total, buffer);
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

	if (field_width > 0)
	{
		field_width -= i;
		field_width_handler(field_width, buffer, count, total);
	}

	for (k = i - 1; k >= 0 && *total < 1024; k--)
	{
		buffer[(*count)++] = hex_buffer[k];
		buffer_status_handler(count, total, buffer);
	}
}

/**
 * int_format_handler - print signed decimal integers
 * (%i: used for input from scanf, %d: any inputted int)
 * @ap: Argument pointer
 * @count: A pointer to the current count of printed characters
 * @total: A pointer to the total number of characters printed
 * @buffer: A pointer to the buffer holding the characters to be printed
 * @field_width: The field width
 */

void int_format_handler(va_list ap, int *count, int *total, char *buffer,
		int field_width)
{
	char int_buffer[20]; /*store digits of interger*/
	int j, i = 0, number = va_arg(ap, int), tmp = number;

	if (number == 0) /*Add '0' to the buffer*/
	{
		field_width -= 1;
		field_width_handler(field_width, buffer, count, total);
		handle_zero_number(count, total, buffer);
		return;
	}
	if (number < 0 && field_width == 0) /*handle negatives*/
	{
		buffer[(*count)++] = '-';
		buffer_status_handler(count, total, buffer);
		number = -number;
	}
	if (number == INT_MIN) /* handle INT_MIN separately */
	{
		int_buffer[i++] = '8';
		number = 214748364; }
	while (number != 0) /*store digits in int_buffer */
	{
		int_buffer[i++] = (number % 10) + '0';
		number /= 10; }
	if (field_width > 0) /* Pads the number with spaces */
	{
		if (tmp < 0)
			field_width -= i + 1;
		else
			field_width -= i;
		field_width_handler(field_width, buffer, count, total);
		if (tmp < 0)
		{
			buffer[(*count)++] = '-';
			buffer_status_handler(count, total, buffer); }
	}
	for (j = i - 1; j >= 0; j--) /*Add int_buffer's contents to buffer*/
	{
		buffer[(*count)++] = int_buffer[j];
		buffer_status_handler(count, total, buffer); }
}
