#include "shell.h"
/**
 * _strtok - Custom implementation of strtok
 * @str: The string to tokenize
 * @delimiters: The delimiter characters
 * Return: Pointer to the next token, or NULL if no more tokens are found
 */
char *_strtok(char *str, const char *delimiters)
{
	static char *next_token;
	char *token_end = NULL;

	if (str == NULL)
	{
	str = next_token;
	}
	str += strspn(str, delimiters);
	if (*str == '\0')
	{
	return (NULL);
	}
	token_end = str + strcspn(str, delimiters);
	if (*token_end != '\0')
	{
	*token_end = '\0';
	next_token = token_end + 1;
	}
	else
	{
	next_token = token_end;
	}
	return (str);
}
