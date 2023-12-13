#include "shell.h"
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
	int MAX = 0, status = 0;
	size_t len = 0;
	char **tokenized = {NULL};

	(void)ac;
	(void)av;
	while (1)
	{
	printer("hell($) ");
	/*get argument from stdin to command*/
	if (getline(&command, &len, stdin) == -1)
	{
		free(command);
		_putchar('\n');
		exit(0);
	}
	/*tokenize arguments*/
	if (*command != '\n')
		{
	clean_newline(command);
	tokenized = malloc(sizeof(char *) * 10);
	MAX = parser(command, tokenized, " ");
	/*Check for EOF*/
	if ((_strcmp(tokenized[0], "exit") == 0))
	{
	if (MAX >= 2)
		status = _atoi(tokenized[1]);
	free(command);
	_free_tok(tokenized, MAX);
	my_exit(status);
	}
	/*execute command*/
	if ((conditions(tokenized, env)) != 0)
		executer(tokenized);
_free_tok(tokenized, MAX);
		}
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
void _free_tok(char **tokenized, int MAX)
{
	int x;

	for (x = 0; x < 10; x++)
	{
		if (x <= MAX)
			free(tokenized[x]);
		tokenized[x] = NULL;
	}
	free(tokenized);
	tokenized = NULL;
}
/**
 * my_exit - exit the program when exit command passed
 * @status: is the status of the program when it exit
 * Return: void
 */
void my_exit(int status)
{
	exit(status);
}
/**
 * clean_newline - clean '\n' char from command
 * @command: is the getline str
 * Return: void
 */
void clean_newline(char *command)
{
	size_t command_length = 0;

	command_length = _strlen(command);
	if (command_length > 0 && command[command_length - 1] == '\n')
	{
	command[command_length - 1] = '\0';
	}
}
