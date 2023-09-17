#include <limits.h>
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

#define BUFFER_SIZE 1024

int putcher(char c)
{
	return write(1, &c, 1);
}

void print_buffer(char *buffer, int *count, int *buffer_index)
{
	*count += write(1, buffer, *buffer_index);
	buffer[0] = '\0';
	*buffer_index = 0;
}

int _printf(const char *format, ...)
{
	va_list vargs;
	const char *ptr;
	int count = 0;
	char buffer[BUFFER_SIZE];
	int buffer_index = 0;

	if (format == NULL)
		return -1;

	va_start(vargs, format);

	for (ptr = format; *ptr != '\0'; ptr++)
	{
		if (*ptr == '%')
		{
			ptr++;
			if (*ptr == 'c')
			{
				char c = (char)va_arg(vargs, int);
				if (buffer_index >= BUFFER_SIZE - 1)
				{
					print_buffer(buffer, &count, &buffer_index);
				}
				buffer[buffer_index++] = c;
			}
			else if (*ptr == 's')
			{
				int len;
				const char *str = va_arg(vargs, char *);
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
			else if (*ptr == 'd' || *ptr == 'i')
			{
				int len, num = va_arg(vargs, int);
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
			else if (*ptr == '%')
			{
				if (buffer_index >= BUFFER_SIZE - 1)
				{
					print_buffer(buffer, &count, &buffer_index);
				}
				buffer[buffer_index++] = '%';
			}
		}
		else
		{
			if (buffer_index >= BUFFER_SIZE - 1)
			{
				print_buffer(buffer, &count, &buffer_index);
			}
			buffer[buffer_index++] = *ptr;
		}
	}

	if (buffer_index > 0)
	{
		print_buffer(buffer, &count, &buffer_index);
	}

	va_end(vargs);
	return count;
}

int main(void)
{
	int len;
	int len2;
	unsigned int ui;
	void *addr;

	len = _printf("Let's try to printf a simple sentence.\n");
	len2 = printf("Let's try to printf a simple sentence.\n");
	ui = (unsigned int)INT_MAX + 1024;
	addr = (void *)0x7ffe637541f0;
	_printf("Length:[%d, %i]\n", len, len);
	printf("Length:[%d, %i]\n", len2, len2);
	_printf("Negative:[%d]\n", -762534);
	printf("Negative:[%d]\n", -762534);
	_printf("Unsigned:[%u]\n", ui);
	printf("Unsigned:[%u]\n", ui);
	_printf("Unsigned octal:[%o]\n", ui);
	printf("Unsigned octal:[%o]\n", ui);
	_printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	_printf("Character:[%c]\n", 'H');
	printf("Character:[%c]\n", 'H');
	_printf("String:[%s]\n", "I am a string !");
	printf("String:[%s]\n", "I am a string !");
	_printf("Address:[%p]\n", addr);
	printf("Address:[%p]\n", addr);
	len = _printf("Percent:[%%]\n");
	len2 = printf("Percent:[%%]\n");
	_printf("Len:[%d]\n", len);
	printf("Len:[%d]\n", len2);
	_printf("Unknown:[%r]\n");
	printf("Unknown:[%r]\n");
	return 0;
}
