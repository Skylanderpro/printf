#include "main.h"

/**
 * handle_format - handle format specifiers
 * @ptr: string argument to printf
 *Return: count
 */
void handle_format(const char *ptr, va_list vargs, char *buffer, int *count,
		int *buffer_index, unsigned int *num)
{
	(*ptr)++;
	if (*ptr == 'c')
	print_c((char)va_arg(vargs, int), buffer, count,
			buffer_index);
	else if (*ptr == 's')
		print_s(va_arg(vargs, char *), buffer, count,
				buffer_index);
	else if (*ptr == 'd' || *ptr == 'i')
		print_di(va_arg(vargs, int), buffer, count,
				buffer_index);
	else if (*ptr == '%')
		print_perc(buffer, count, buffer_index);
	else if (*ptr == 'b')
	{
		*num = va_arg(vargs, unsigned int);
		print_binary(*num, buffer, count, buffer_index);
	}
	else if (*ptr == 'u')
	{
		*num = va_arg(vargs, unsigned int);
		print_unsigned_int(*num, buffer, count, buffer_index);
	}
	else if (*ptr == 'o')
		print_octal(*num, buffer, count, buffer_index);
	else if (*ptr == 'x')
		print_hexad_lower(num, buffer, &count, &buffer_index);
	else if (*ptr == 'X')
		print_hexad_upper(*num, buffer, count, buffer_index);
	else
	{
		if (*buffer_index >= BUFFER_SIZE - 1)
			print_buffer(buffer, count, buffer_index);
		buffer[(*buffer_index)++] = **ptr;
	}
}
