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
	size_t len = 0;

	if (str == NULL)
	{
	return (NULL);
	}

	len = _strlen(str);

	dup = my_calloc((len + 1), sizeof(char));
	if (dup == NULL)
	{
	perror("Memory allocation for _strdup failer");
	exit(1);
	}

	for (x = 0; str[x]; x++)
	{
	dup[x] = str[x];
	}
	dup[x] = '\0';
	return (dup);
}
