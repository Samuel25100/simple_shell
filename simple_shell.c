#include "shell.h"
/**
 * main - print "simple_shell$ " and wait for command
 * Return: 0 success
 */
int main(int ac, char **av, char **env)
{
	char *command;
	size_t len = 0, command_length = 0;
	char *tokenized[MAX_ARGS];

	(void)ac;
	(void)av;
	while (1)
	{
	printer("hell($) ");
	/*get argument from stdin to command*/
	if (getline(&command, &len, stdin) == -1)
	{
		break;
	}
	/*tokenize arguments*/
	command_length = _strlen(command);
	if (command_length > 0 && command[command_length - 1] == '\n')
	{
	command[command_length - 1] = '\0';
	}
	parser(command, tokenized, " ");
	/*Check for EOF*/
	if (feof(stdin) || (_strcmp(tokenized[0], "exit") == 0))
	{
	free(command);
	my_exit();
	}
	/*execute command*/
	if ((conditions(tokenized, env)) != 0)
		executer(tokenized);
	}
	free(command);
	return (0);
}
