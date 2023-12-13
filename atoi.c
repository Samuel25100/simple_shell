#include "shell.h"
/**
 * _atoi - convert a string to an integer
 * @s: the string
 * Return: the int
 */
int _atoi(char *s)
{
	int x, sign = 1;
	unsigned int y = 0;

	for (x = 0; *(s + x); x++)
	{
		if (*(s + x) == '-')
		{
		sign = sign * -1;
		}
		if (*(s + x) >= 48 && *(s + x) <= 57)
		{
			y = (y * 10) + (*(s + x) - '0');
		if (!((*(s + x + 1) >= 48) && (*(s + x + 1) <= 57)))
			{
			break;
			}
		}
	}
	y = y * sign;
	return (y);
}
