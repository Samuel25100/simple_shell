#include "shell.h"
void _free_tok(char *tokenized[MAX_ARGS], int MAX);
/**
 * main - print "simple_shell$ " and wait for command
 * @ac: num of argument
 * @av: the array of each argument
 * @env: arrary of each enviroment
 * Return: 0 success
 */
int main(int ac, char **av, char **env)
{
	char *command = NULL;
	int MAX = 0;
	size_t len = 0, command_length = 0;
	char *tokenized[MAX_ARGS] = {NULL};

	(void)ac;
	(void)av;
	while (1)
	{
	printer("hell($) ");
	/*get argument from stdin to command*/
	if (getline(&command, &len, stdin) == -1)
	{
		free(command);
		if (MAX != 0)
			_free_tok(tokenized, MAX);
		my_exit();
	}
	/*tokenize arguments*/
	command_length = _strlen(command);
	if (command_length > 0 && command[command_length - 1] == '\n')
	{
	command[command_length - 1] = '\0';
	}
	MAX = parser(command, tokenized, " ");
	/*Check for EOF*/
	if (feof(stdin) || (_strcmp(tokenized[0], "exit") == 0))
	{
	free(command);
	_free_tok(tokenized, MAX);
	my_exit();
	}
	/*execute command*/
	if ((conditions(tokenized, env)) != 0)
		executer(tokenized);
	_free_tok(tokenized, MAX);
	}
	free(command);
	return (0);
}
/**
 * _free_tok - free tokenized
 * @tokenized: the token of user input command
 * @MAX: number of pointer in the array that allocated
 * Return: void
 */
void _free_tok(char *tokenized[MAX_ARGS], int MAX)
{
	int x;

	for (x = 0; x <= MAX; x++)
	{
	if (tokenized[x])
		free(tokenized[x]);
	}
}
/**
 * my_exit - exit the program when exit command passed
 * Return: void
 */
void my_exit(void)
{
	printer("Exiting succeed");
	_putchar('\n');
	exit(1);
}
