#include "main.h"
/**
 *_strlen - gets the string length
 *@s: the string to print
 *Return: lenght of the string or 0 for error
 */
int _strlen(char *s)
{
	if (s == NULL || *s == '\0')
	{
		return (0);
	}
	return (1 + _strlen(s + 1));
}

/**
 *_strncpy - copies a string into another
 *@dest: destination string
 *@src: source string
 *@n: number of characters copied
 *Return: destination string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}

	return (dest);
}
