#include "shell.h"
/**
 * printer - print the str
 * @str: the string
 * Return: number of print
 */
int printer(char *str)
{
	int count = 0;

	while (*(str + count))
	{
	_putchar(*(str + count));
	count++;
	}
	return (count);
}
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * _strlen - return the lenght of string
 * @str: the string
 * Return: the len
 */
int _strlen(char *str)
{
	int count = 0;

	while (str[count])
		count++;
	return (count);
}
