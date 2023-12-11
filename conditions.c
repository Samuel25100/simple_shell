#include "shell.h"
/**
 * conditions - check many conditions before calling executer
 * @command: tokenized command or user input
 * Return: 1 if there is no conditions, if any 0
 */
int conditions(char *tokenized[MAX_ARGS])
{
	if (_strcmp(tokenized[0],"env") == 0)
	{
	my_env();
	return (0);
	}
	else if (_strcmp(tokenized[0],"cd") == 0)
	{
	/*my_exit();*/
	return (0);
	}
	return (1);
}
/**
 * my_env - print all enviroments
 * Return: void
 */
void my_env(void)
{
	extern char **environ;
	int x = 0;

	while (*(environ + x) != NULL)
	{
	printer(*(environ + x));
	x++;
	}
	_putchar('\n');
}
void my_exit(void)
{
	printer("Exiting succeed");
	_putchar('\n');
	exit(1);
}
