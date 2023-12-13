#include "shell.h"
/**
 * print_error - print error message
 * @tokenized: tokenized user input
 * @err: the string of error message
 * Return: void
 */
void print_error(char *tokenized[MAX_ARGS], char *err)
{
	int count = 0;

	while (tokenized[count])
	{
	count++;
	}
	printer(getenv("_"));
	printer(": ");
	_putchar(count + '0');
	printer(": ");
	printer(tokenized[0]);
	printer(": ");
	printer(err);
	_putchar('\n');
}
