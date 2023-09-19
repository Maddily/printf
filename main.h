#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define BUFFER_SIZE 1024
#define PLUS_FLAG
#define SPACE_FLAG
#define HASH_FLAG
#define ZERO_FLAG

#define UNUSED(x) (void)(x)

/**
 * struct fmt_specifier - A structure of a specifier
 * and its corresponding function pointer
 * @spec: A specifier (s, c, i, d,...)
 * @hndlr: A pointer to a function that doesn't return a value
 */
typedef struct fmt_specifier
{
	char spec;
	void (*hndlr)(va_list ap, int *count, int *total, char *buffer,
			int field_width);
} fmt_spec;

int _printf(const char *format, ...);
int find_length(char *s);
int find_const_length(const char *s);
char hex_to_ascii(int digit);
void fill_buffer(const char *format, int *count, int *total, char *buffer);
int handle_all(const char *format, va_list ap, int *count, int *total,
		char *buffer, fmt_spec *spec);
int handle_struct(const char *format, fmt_spec *spec, va_list ap, int *count,
		int *total, char *buffer, int field_width);
void buffer_status_handler(int *count, int *total, char *buffer);
void field_width_handler(int field_width, char *buffer, int *count,
		int *total);
int precision_handler(const char *format, int precision, va_list ap,
		char *buffer, int *count, int *total);

void char_format_handler(va_list ap, int *count, int *total, char *buffer,
		int field_width);
void str_format_handler(va_list ap, int *count, int *total, char *buffer,
		int field_width);
void ptr_format_handler(va_list ap, int *count, int *total, char *buffer,
		int field_width);
void percent_handler(int *count, int *total, char *buffer);
void handle_zero_number(int *count, int *total, char *buffer);

/* --------- Numbers ------*/
void int_format_handler(va_list ap, int *count, int *total, char *buffer,
		int field_width);
void u_format_handler(va_list ap, int *count, int *total, char *buffer,
		int field_width);
void o_format_handler(va_list ap, int *count, int *total, char *buffer,
		int field_width);
void x_format_handler(va_list ap, int *count, int *total, char *buffer,
		int field_width);
void printUpperHex(va_list ap, int *count, int *total, char *buffer,
		int field_width);

/* --------- Characters ----*/
int our_ptchar(char c);
char *intToString(int num);


/*--- Custom Format Specifiers ---*/
void custom_b_handler(va_list ap, int *count, int *total, char *buffer,
		int field_width);
void custom_S_handler(va_list ap, int *count, int *total, char *buffer,
		int field_width);
void custom_r_handler(va_list ap, int *count, int *total, char *buffer,
		int field_width);
void custom_R_handler(va_list ap, int *count, int *total, char *buffer,
		int field_width);

/*--- Length Modifiers ---*/
void long_modifier_handler(const char *format, va_list ap, int *count,
		int *total, char *buffer);
void long_int_handler(long number, int *count, int *total, char *buffer);
void long_u_handler(unsigned long number, int *count,
		int *total, char *buffer);
void long_o_handler(unsigned long number, int *count,
		int *total, char *buffer);
void long_x_handler(unsigned long number, int *count,
		int *total, char *buffer);
void long_upper_x_handler(unsigned long number, int *count,
		int *total, char *buffer);
void short_modifier_handler(const char *format, va_list ap,
		int *count, int *total, char *buffer);
void short_int_handler(short number, int *count, int *total, char *buffer);
void short_u_handler(unsigned short number, int *count,
		int *total, char *buffer);
void short_o_handler(unsigned short number, int *count,
		int *total, char *buffer);
void short_x_handler(unsigned short number, int *count,
		int *total, char *buffer);
void short_upper_x_handler(unsigned short number, int *count,
		int *total, char *buffer);

/*--- Error ---*/
int trailing_percent_error(const char *format);

/*--- Flags -----*/

#endif
