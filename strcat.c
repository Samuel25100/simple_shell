#include "shell.h"
/**
 * _strcat - concatenates src on dest string
 * @dest: the destination string
 * @src: the source string
 * Return: pointer to dest
 */
char *_strcat(char *dest, char *src)
{
	int x, y;

	x = 0;
	while (*(dest + x))
	{
	x++;
	}
	for (y = 0; *(src + y); y++)
	{
	*(dest + x) = *(src + y);
	x++;
	}
	*(dest + x) = '\0';
	return (dest);
}
