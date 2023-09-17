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
