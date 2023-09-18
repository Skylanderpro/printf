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
			handle_format(&ptr, vargs, buffer, &count, &buffer_index, &num);
		}
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
