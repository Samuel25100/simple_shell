#include "shell.h"
/**
 * parser - parse the string using delimiter space in argument
 * @command: the string
 * @delim: delimeter to parsing or tokenizing
 * @args: array of pointer to put each token
 * Return: Number of token, O if non
 */
int parser(char *command, char **args, char *delim)
{
	char *token = NULL;
	int argc = 0;

	token = strtok(command, delim);
	while (token != NULL)
	{
	args[argc] = _strdup(token);
	token = strtok(NULL, delim);
	argc++;
	}
	args[argc] = NULL;
	return (argc);
}
/**
 * _memset - initalize memory with some value to avoid junk value
 * @str: the pointer to memory which value is inserted on
 * @fill: the value to be insert into memory
 * @size: the size of memory
 * Return: void
 */
void _memset(char *str, int fill, int size)
{
	int x = 0;

	for (x = 0; x < size && str[x]; x++)
	{
	str[x] = (unsigned char)fill;
	}
}
