#include "shell.h"
void free_result(char **result);
/**
 * get_path - recive tokenized "PATH" and check path exist and return it
 * @file: the string to contacenate on path or file name
 * Return: existed and executable file path
 */
char *get_path(char *file)
{
	char *path = NULL;
	char *tok_copy = NULL;

	path = getenv("PATH");
	if (path == NULL)
	{
	perror("Error in getenv");
	}
	path = _strdup(path);
	tok_copy = add_command(path, file);
	free(path);
	if (tok_copy != NULL)
	{
	return (tok_copy);
	}
	return (NULL);
}
/**
 * add_command - tokenized, add inserted command to the each pathes,
 * and check file status
 * @path: the array of pointers to each pathes
 * @file: the first argument from getline or it file name
 * Return: pointer to the string of file absolute path
 */
char *add_command(char *path, char *file)
{
	int x = 0;
	char **result = NULL, *path_c = NULL;
	char *token = NULL, *result_c = NULL;

	path_c = _strdup(path);
	token = strtok(path_c, ":");
	result = malloc(sizeof(char *) * 25);
	if (result == NULL)
	{
	perror("Malloc Error");
	exit(97);
	}
	while (token)
	{
	result[x] = malloc(_strlen(token) + _strlen(file) + 2);
		if (result[x] == NULL)
		{
		perror("Malloc Error");
		exit(97);
		}
	_strcpy(result[x], token);
	_strcat(result[x], "/");
	_strcat(result[x], file);
	token = strtok(NULL, ":");
		if ((access(result[x], F_OK | X_OK) == 0))
		{
		free(path_c);
		result_c = _strdup(result[x]);
		free_result(result);
		return (result_c);
		}
	x++;
	}
	free(path_c);
	free_result(result);
	return (NULL);
}
/**
 * free_result - free the pointer result
 * @result: is the pointer
 * Return: void
 */
void free_result(char **result)
{
	int x = 0;

	for (x = 0; result[x]; x++)
	{
	free(result[x]);
	}
	free(result);
}
