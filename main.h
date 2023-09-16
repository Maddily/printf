#ifndef HEADER_H
#define HEADER_H

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int _printf(const char *format, ...);
int find_length(char *s);

void char_format_handler(va_list ap, char character, int count);
void str_format_handler(char *string, int count, int len, char *null);
void percent_handler(char character, int count);
void default_handler(char character, const char *format, int count);

/* --------- Numbers ------*/
void int_format_handler(int number, int count);
void u_format_handler(unsigned int number, int count);
void o_format_handler(unsigned int number, int count);
void x_format_handler(unsigned int number, int count);
void printUpperHex(unsigned int number, int count);

/* --------- Characters ----*/
int our_ptchar(char c);
void print_S(char *string, int count, int len, char *null);

/*--- Custom Format Specifiers ---*/
void custom_b_handler(va_list ap, int count);

#endif
