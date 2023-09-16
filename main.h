#ifndef HEADER_H
#define HEADER_H

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define BUFFER_SIZE 1024

int _printf(const char *format, ...);
int find_length(char *s);
int find_const_length(const char *s);

void char_format_handler(va_list ap, int *count, int *total, char *buffer);
void str_format_handler(char *string, int *count, int *total, char *buffer);
void percent_handler(int *count, int *total, char *buffer);
void default_handler(const char *format, int *count, int *total, char *buffer);

/* --------- Numbers ------*/
void int_format_handler(int num, int *count, int *total, char *buffer);
void u_format_handler(unsigned int number, int count);
void o_format_handler(unsigned int number, int count);
void x_format_handler(unsigned int number, int count);
void printUpperHex(unsigned int number, int count);

/* --------- Characters ----*/
int our_ptchar(char c);
void print_S(char *string, int count, int len, char *null);

/*--- Custom Format Specifiers ---*/
void custom_b_handler(va_list ap, int *count, int *total, char *buffer);

/*--- Error Messages ---*/
void trailing_percent_error(const char *format);

#endif
