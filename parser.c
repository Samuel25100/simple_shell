#include "shell.h"
/**
 * parser - parse the string using delimiter space in argument
 * @command: the string
 * @delim: delimeter to parsing or tokenizing
 * Return: 0 success
 */
void parser(char *command, char *args[MAX_ARGS], char *delim)
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
}
