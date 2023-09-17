#include "main.h"
/**
 *print_buffer - prints the buffer
 *@buffer: stores a string to print
 *@count: number of printed characters
 *@buffer_index: characters in buffer
 */
void print_buffer(char *buffer, int *count, int *buffer_index)
{
	*count += write(1, buffer, *buffer_index);
	buffer[0] = '\0';
	*buffer_index = 0;
}
/**
 *print_c - adds a character to buffer
 *@c: the char to add
 */
void print_c(char c)
{
	if (buffer_index >= BUFFER_SIZE - 1)
	{
		print_buffer(buffer, &count, &buffer_index);
	}
	buffer[buffer_index++] = c;
}
/**
 *print_s - adds a string to buffer
 *@str: the string to add
 */
void print_s(const char *str)
{
	int len;

	if (str == NULL)
	{
		str = "(null)";
	}
	len = strlen(str);
	if (buffer_index + len >= BUFFER_SIZE - 1)
	{
		print_buffer(buffer, &count, &buffer_index);
	}
	strncpy(buffer + buffer_index, str, len);
	buffer_index += len;
}
/**
 *print_di - adds %d and %i arguments of printf to buffer
 *@num: the integer to add
 */
void print_di(int num)
{
	int len;
	char num_str[20];
	snprintf(num_str, sizeof(num_str), "%d", num);
	len = strlen(num_str);
	if (buffer_index + len >= BUFFER_SIZE - 1)
	{
		print_buffer(buffer, &count, &buffer_index);
	}
	strncpy(buffer + buffer_index, num_str, len);
	buffer_index += len;
}
/**
 *print_perc - adds percent to buffer
 */
void print_perc(void)
{
	if (buffer_index >= BUFFER_SIZE - 1)
		print_buffer(buffer, &count, &buffer_index);
	buffer[buffer_index++] = '%';
}
