#include "main.h"

/**
 * print_char - Print a single character and return the character count.
 * @c: Character to be printed.
 *
 * Return: Number of characters printed (always 1 for a single character).
 */
int print_char(char c)
{
	putchar(c);
	return (1);
}

/**
 * print_string - Print a string and return the character count.
 * @str: String to be printed.
 *
 * Return: Number of characters printed.
 */
int print_string(const char *str)
{
	int count = 0;

	while (*str)
	{
		putchar(*str);
		str++;
		count++;
	}
	return (count);
}

/**
 * _printf - Custom printf function to handle %c, %s, and %% specifiers.
 * @format: Format string containing specifiers.
 *
 * Return: Total number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list args;
	const char *ptr;
	int count = 0;

	va_start(args, format);

	for (ptr = format; *ptr != '\0'; ptr++)
	{
		if (*ptr == '%')
		{
			ptr++;
			if (*ptr == 'c')
			{
				char c = (char)va_arg(args, int);

				count += print_char(c);
			}
			else if (*ptr == 's')
			{
				char *s = va_arg(args, char *);

				count += print_string(s);
			}
			else if (*ptr == '%')
			{
				putchar('%');
				count++;
			}
		}
		else
		{
			putchar(*ptr);
			count++;
		}
	}

	va_end(args);

	return (count);
}

