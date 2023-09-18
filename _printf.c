#include "main.h"

/**
 *_printf - custom printf function
 *@format: string argument to printf
 *Return: count
 */
int _printf(const char *format, ...)
{
	va_list vargs;
	const char *ptr;
	int count = 0, buffer_index = 0;
	char buffer[BUFFER_SIZE];
	unsigned int num;

	if (format == NULL)
		return (-1);

	va_start(vargs, format);

	for (ptr = format; *ptr != '\0'; ptr++)
	{
		if (*ptr == '%')
		{
			ptr++;
			if (*ptr == 'c')
				print_c((char)va_arg(vargs, int), buffer, &count,
						&buffer_index);
			else if (*ptr == 's')
				print_s(va_arg(vargs, char *), buffer, &count,
						&buffer_index);
			else if (*ptr == 'd' || *ptr == 'i')
				print_di(va_arg(vargs, int), buffer, &count,
						&buffer_index);
			else if (*ptr == '%')
				print_perc(buffer, &count, &buffer_index);
			else if (*ptr == 'b')
			{
				num = va_arg(vargs, unsigned int);
				print_binary(num, buffer, &count, &buffer_index);
			}
			else if (*ptr == 'u')
				print_unsigned(num, buffer, &count, &buffer_index);
			else if (*ptr == 'o')
				print_octal(num, buffer, &count, &buffer_index)
			else if (*ptr == 'x')
				print_hexad_lower(num, buffer, &count, &buffer_index);
			else if (*ptr == 'X')
				print_hexad_upper(num, buffer, &count, &buffer_index);
		else
		{
			if (buffer_index >= BUFFER_SIZE - 1)
				print_buffer(buffer, &count, &buffer_index);
			buffer[buffer_index++] = *ptr;
		}
	}

	if (buffer_index > 0)
		print_buffer(buffer, &count, &buffer_index);

	va_end(vargs);
	return (count);
}
