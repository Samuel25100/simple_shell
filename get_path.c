#include "shell.h"
void free_result(char **result);
/**
 * get_path - recive tokenized "PATH" and check path exist and return it
 * @file: the string to contacenate on path or file name
 * Return: existed and executable file path
 */
char *get_path(char *file)
{
	char *path = NULL, *path_c = NULL;
	char *tok_copy = NULL;

	path = getenv("PATH");
	if (path == NULL)
	{
	perror("Error in getenv");
	}
	path_c = _strdup(path);
	tok_copy = add_command(path_c, file);
	free(path_c);
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
	char **result = {NULL}, *path_c = NULL;
	char *token = NULL, *result_c = NULL;

	path_c = _strdup(path);
	token = _strtok(path_c, ":");
	result = my_calloc(25,sizeof(char *));
	if (result == NULL)
	{
	perror("Malloc Error");
	exit(97);
	}

	while (token)
	{
	result[x] = my_calloc((_strlen(token) + _strlen(file) + 2),sizeof(char));
		if (result[x] == NULL)
		{
		perror("Malloc Error");
		exit(97);
		}
	if (result[x] != NULL)
	{
	_strcpy(result[x], token);
	_strcat(result[x], "/");
	_strcat(result[x], file);
	}
	token = _strtok(NULL, ":");
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
	result[x] = NULL;
	}
	free(result);
	result = NULL;
}
