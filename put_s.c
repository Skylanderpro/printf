#include "main.h"
/**
 *put_s - prints a string
 *@s: the string to print
 *@count: number of printed chars
 *
 *Return: 0
 */
int put_s(char *s, int count)
{
	while (*s)
	{
		putchar(*s);
		s++;
		count++;
	}
	return (count);
}
