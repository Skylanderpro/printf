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
		if (str == NULL)
		{
			str = "";
		}
		putchar(*str);
		str++;
		count++;
	}
	return (count);
}

/**
 * print_integer - Print an integer and return the character count.
 * @n: Integer to be printed.
 *
 * Return: Number of characters printed.
 */
int print_integer(int n)
{
	int count = 0, digit, i, num = n, divisor, temp, num_digits = 1;

	if (n < 0)
	{
		putchar('-');
		num = -num;
		count++;
	}


	temp = num;
	while (temp > 9)
	{
		temp /= 10;
		num_digits++;
	}

	divisor = 1;

	for (i = 1; i < num_digits; i++)
		divisor *= 10;

	count++;
	while (divisor > 0)
	{
		digit = num / divisor;
		putchar('0' + digit);
		count++;
		num -= digit * divisor;
		divisor /= 10;
	}

	return (count);
}

/**
 *put_perc - prints percent
 *Return: number of printed characters
 */
int put_perc(void)
{
	putchar('%');
	return (1);
}

/**
 * _printf - Custom printf function, handle %c,%s,%d,%i,and %% specifiers.
 * @format: Format string containing specifiers.
 *
 * Return: Total number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list vargs;
	const char *ptr;
	int count = 0;

	if (format == NULL)
		return (-1);

	va_start(vargs, format);

	for (ptr = format; *ptr != '\0'; ptr++)
	{
		if (*ptr == '%')
		{
			ptr++;
			if (*ptr == 'c')
			{
				count += print_char((char)va_arg(vargs, int));
			}
			else if (*ptr == 's')
			{
				count += print_string(va_arg(vargs, char *));
			}
			else if (*ptr == 'd' || *ptr == 'i')
			{
				count += print_integer(va_arg(vargs, int));
			}
			else if (*ptr == '%')
			{
				count += put_perc();
			}
		}
		else
		{
			putchar(*ptr);
			count++;
		}
	}

	va_end(vargs);
	putchar('\n');
	return (count);
}
