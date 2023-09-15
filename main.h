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
void int_format_handler(int num, int count);

/* --------- Characters ----*/
int our_ptchar(char c);

/*--- Custom Format Specifiers ---*/
void custom_b_handler(va_list ap, int count);

#endif
