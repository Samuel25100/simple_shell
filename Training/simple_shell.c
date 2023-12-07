#include "shell.h"
/**
 * main - print "simple_shell$ " and wait for command
 * Return: 0 success
 */
int main(void)
{
	char *command = NULL;
	size_t len = 0, command_length = 0;
	char **tokenized = NULL;

	while (1)
	{
	printer("simple_shell$ ");
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
	tokenized = malloc(sizeof(char *) * 1024);
	tokenized = parser(command, " \n");
	/*execute command*/
	executer(tokenized);
	if (feof(stdin))
	{
	free(tokenized);
	exit(1);
	}
	}
	return (0);
}
