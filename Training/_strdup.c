#include "shell.h"
/**
 * _strdup - duplicate the str by returning the str
 * @str: the string
 * Return: the pointer to string
 */
char *_strdup(char *str)
{
	char *dup = NULL;
	int x = 0;
	size_t len = _strlen(str);

	if (str == NULL)
	{
	return (NULL);
	}
	dup = malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
	{
	perror("Memory allocation for _strdup failer");
	exit(1);
	}
	for (x = 0; *(str + x); x++)
	{
	*(dup + x) = *(str + x);
	}
	return (dup);
}
