#ifndef MAIN_H
#define MAIN_H
#define BUFFER_SIZE 1024
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

int _printf(const char *format, ...);
void print_buffer(char *buffer, int *count, int *buffer_index);
void print_c(char c, char *buffer, int *count, int *buffer_index);
void print_s(const char *str, char *buffer, int *count, int *buffer_index);
void print_di(int num, char *buffer, int *count, int *buffer_index);
void print_perc(char *buffer, int *count, int *buffer_index);
void print_binary(unsigned int num, char *buffer, int *count, int *buffer_index);
void print_unsigned_int(unsigned int, char *buffer, int *count, int *buffer_index);
void print_octal(unsigned int, char *buffer, int *count, int *buffer_index);
void print_hexad_lower(unsigned int, char *buffer, int *count, int *buffer_index);
void print_hexad_upper(unsigned int, char *buffer, int *count, int *buffer_index);

#endif
