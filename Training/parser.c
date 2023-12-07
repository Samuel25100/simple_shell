#include "shell.h"
/**
 * parser - parse the string using delimiter space in argument
 * @command: the string
 * @delim: delimeter to parsing or tokenizing
 * Return: 0 success
 */
char **parser(char *command, char *delim)
{
	char *token = NULL;
	char **argv = NULL;
	int argc = 0;

	token = strtok(command, delim);
	while (token != NULL)
	{
	argv = realloc(argv, (argc + 2) * sizeof(char *));
	argv[argc] = _strdup(token);
	argv[++argc] = NULL;
	token = strtok(NULL, delim);
	}
	return (argv);
}
