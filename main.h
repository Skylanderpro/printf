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

char *_strncpy(char *dest, char *src, int n);
int _strlen(char *s);
int _printf(const char *format, ...);
void print_buffer(char *buffer, int *count, int *buffer_index);
void print_c(char c, char *buffer, int *count, int *buffer_index);
void print_s(const char *str, char *buffer, int *count, int *buffer_index);
void print_di(int num, char *buffer, int *count, int *buffer_index);
void print_perc(char *buffer, int *count, int *buffer_index);

#endif
