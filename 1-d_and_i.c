#include "main.h"

/**
 * print_dec - Function to print d
 * @dec: integer no
 * @count: Int that counts characters printed
 * Return: Returns the count
 */

int print_d(int num)
{
 	int count = 0;

	if (num)
	{
		putchar('-');
		count++;
		num = -num;
	}

	if (num / 10)
	{
		count += print_d(num / 10);
	}

	putchar('0' + num % 10);
	count++;

	return (count);
}
