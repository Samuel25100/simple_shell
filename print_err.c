#include "shell.h"
/**
 * print_error - print error message
 * @tokenized: tokenized user input
 * @err: the string of error message
 * Return: void
 */
void print_error(char **tokenized, char *err)
{
	int count = 0;

	while (tokenized[count] != NULL)
	{
	count++;
	}
	printer(getenv("_"));
	printer(": ");
	count = count - 1;
	_putchar(count + '0');
	printer(": ");
	printer(tokenized[0]);
	printer(": ");
	printer(err);
	_putchar('\n');
}
