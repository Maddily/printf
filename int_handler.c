#include "main.h"

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
