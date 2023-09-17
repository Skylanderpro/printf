#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

int _printf(const char *format, ...);
void print_buffer(char *buffer, int *count, int buffer_index);
void print_c(char c);
void print_s(const char *str);
void print_di(int num);
void print_perc(void);

#endif
