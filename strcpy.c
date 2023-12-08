#include "shell.h"
/**
 * _strcpy - copy the string from src to dest
 * @src: source of string
 * @dest: destination of string
 * Return: pointer of dest
 */
char *_strcpy(char *dest, char *src)
{
	int x;

	for (x = 0; *(src + x); x++)
	{
	*(dest + x) = *(src + x);
	}
	*(dest + x) = '\0';
	return (dest);
}
