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
	char *s, p;

	y = strlen(format);
	va_start(vargs, format);
	for (v = 0; v < y; v++)
	{
		if (format[v] == '%')
		{
			v++;
			if (format[v] == 's')
			{
				s = va_arg(vargs, char*);
				while (*s)
				{
					putchar(*s);
					s++;
					count++;
				}
			}
			if (format[v] == 'c')
			{
				p = va_arg(vargs, int);
				putchar(p);
				count++;
			}
			if (format[v] == '%')
			{
				putchar('%');
				count++;
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
