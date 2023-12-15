#include "shell.h"
/**
 * conditions - check many conditions before calling executer
 * @tokenized: tokenized command or user input
 * @env: array of each enviroment
 * Return: 1 if there is no conditions, if any 0
 */
int conditions(char *tokenized[MAX_ARGS], char **env)
{
	if (_strcmp(tokenized[0], "env") == 0)
	{
	my_env(env);
	return (0);
	}
	else if (_strcmp(tokenized[0], "cd") == 0)
	{
	/*my_exit();*/
	return (0);
	}
	else if (_strcmp(tokenized[0], "setenv") == 0)
	{
	return (0);
	}
	return (1);
}
/**
 * my_env - print all enviroments
 * @env: array of each enviroment
 * Return: void
 */
void my_env(char **env)
{
	int x = 0;

	while (env[x] != NULL)
	{
	printer(env[x]);
	_putchar('\n');
	x++;
	}
}
