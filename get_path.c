#include "shell.h"
char *add_command(char *path, char *token);
/**
 * get_path - recive tokenized "PATH" and check path exist and return it
 * @file: the string to contacenate on path or file name
 * Return: existed and executable file path
 */
char *get_path(char *file)
{
	char *path = NULL;
	char *tok_copy = NULL;

	if (file[0] == '/')
	{
	return (file);
	}
	path = getenv("PATH");
	if (path == NULL)
	{
	perror("Error in getenv");
	}
	tok_copy = add_command(path, file);
	if (tok_copy != NULL)
		return (tok_copy);
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
	struct stat file_loc;
	char *result = NULL, *path_c = NULL;
	char *token = NULL;

	path_c = strdup(path);
	token = strtok(path_c, ":");
	while (token)
	{
		if (result)
		{
		free(result);
		result = NULL;
		}
	result = malloc(_strlen(token) + _strlen(file));
		if (result == NULL)
		{
		perror("Malloc Error");
		exit(97);
		}
	_strcpy(result, token);
	_strcat(result, "/");
	_strcat(result, file);
		if ((stat(result, &file_loc) == 0) && (access(result, F_OK | X_OK) == 0))
		{
		free(path_c);
		return (result);
		}
		token = strtok(NULL, ":");
	}
	free(path_c);
	if (result)
	{
	free(result);
	}
	return (NULL);
}
