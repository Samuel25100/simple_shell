#include "shell.h"
/**
 * _strcmp - compares two strings and return
 * @s1: string one
 * @s2: string two
 * Return: result
 */
int _strcmp(char *s1, char *s2)
{
	int x = 0, y = 0;

	for (x = 0; s1[x] && s2[x]; x++)
	{
	y = s1[x] - s2[x];
	if (y != 0)
	{
	return (y);
	}
	}
	return (0);
}
