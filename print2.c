#include "main.h"

/**
 * print_binary - Function to covert unsigned int to binary
 * @num: unsigned int argument
 * @buffer: stores binary to print
 * @count: no of printed chars
 * @buffer_index: chars in buffer
 */

void print_binary(unsigned int num, char *buffer, int *count,
		int *buffer_index)
{
	char binary[33];
	int index = 0;
	int b, begin, end;
	char temp;

	if (num == 0)
	{
		binary[index++] = '0';
	}
	else
	{
		while (num > 0)
		{
			binary[index++] = (num & 1) ? '1' : '0';
			num >>= 1;
		}
	}
	binary[index] = '\0';

	begin = 0;
	end = index - 1;

	while (begin < end)
	{
		temp = binary[begin];
		binary[begin] = binary[end];
		binary[end] = temp;
		begin++;
		end--;
	}
	for (b = 0; binary[b] != '\0'; b++)
	{
		if (*buffer_index >= BUFFER_SIZE - 1)
			print_buffer(buffer, count, buffer_index);
		buffer[(*buffer_index)++] = binary[b];
	}
}

/**
 * print_unsigned - Function to print unsigned values
 *@num: unsigned int
 *@buffer: stores chars to print
 *@count: No of printed char
 *@buffer_index: chars in buffer
 */

void print_unsigned(unsigned int num, char *buffer, int *count, int *buffer_index)
{
	char num_str[20];
	int len, b;

	snprintf(num_str, sizeof(num_str), "%u", num);
	len = strlen(num_str);

	for (b = 0; b < len; b++)
	{
		if (*buffer_index >= BUFFER_SIZE - 1)
			print_buffer(buffer, count, buffer_index);
		buffer[(*buffer_index)++] = num_str[b];
	}
}

/**
 * print_octal - Function to print octal nos
 * @num: unsigned int
 * @buffer: stores chars to be printed
 * @count: no of chars printed
 * @buffer_index: chars in buffer
 */
void print_octal(unsigned int num, char *buffer, int *count, int *buffer_index)
{
	char octal_str[20];
	int len, i;

	snprintf(octal_str, sizeof(octal_str), "%o", num);
	len = strlen(octal_str);

	for (i = 0; i < len; i++)
	{
		if (*buffer_index >= BUFFER_SIZE - 1)
			print_buffer(buffer, count, buffer_index);
		buffer[(*buffer_index)++] = octal_str[i];
	}
}

/**
 * print_hexad_lower - print hexadecimal values in small letters
 * @num: unsigned int
 * @buffer: storeschars to be printed
 * @count: no of chars printed
 * @buffer_index: chars in buffer
 */
void print_hexad_lower(unsigned int num, char *buffer, int *count,
		int *buffer_index)
{
	char hex_str[20];
	int len, l;

	snprintf(hex_str, sizeof(hex_str), "%x", num);
	len = strlen(hex_str);

	for (l = 0; l < len; l++)
	{
		if (*buffer_index >= BUFFER_SIZE - 1)
			print_buffer(buffer, count, buffer_index);
		buffer[(*buffer_index)++] = hex_str[l];
	}
}

/**
 * print_hexad_upper - Function to printhexadecimal in caps
 * @num: unsigned int
 * @buffer: stores chars to print
 * @count: no of chars printed
 * @buffer_index: chars in buffer
 */
void print_hexad_upper(unsigned int num, char *buffer, int *count,
		int *buffer_index)
{
	char hex_str[20];
	int len, u;

	snprintf(hex_str, sizeof(hex_str), "%X", num);
	len = strlen(hex_str);

	for (u = 0; u < len; u++)
	{
		if (*buffer_index >= BUFFER_SIZE - 1)
			print_buffer(buffer, count, buffer_index);
		buffer[(*buffer_index)++] = hex_str[u];
	}
}
