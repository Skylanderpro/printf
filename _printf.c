#include "main.h"
/**
 * _printf - Function to produce output according to a format
 * @format: constant char
 * Return: No of characters printed
 */
int _printf(const char *format, ...)
{
	va_list vargs;
	int v, y, count = 0;
	char p;

	y = strlen(format);
	va_start(vargs, format);
	for (v = 0; v < y; v++)
	{
		if (format[v] == '%')
		{
			v++;
			if (format[v] == 's')
			{
				put_s(va_arg(vargs, char*), count);
			}
			else if (format[v] == 'c')
			{
				p = (char) va_arg(vargs, int);
				putchar(p);
				count++;
			}
			else if (format[v] == '%')
			{
				putchar('%');
				count++;
			}
			else
			{
				continue;
			}
		}
		else
		{
			putchar(format[v]);
			count++;
		}
	}
	va_end(vargs);
	return (count);
}
