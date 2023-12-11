#include "shell.h"
/**
 * main - print "simple_shell$ " and wait for command
 * Return: 0 success
 */
int main(void)
{
	char *command = NULL;
	size_t len = 0, command_length = 0;
	char *tokenized[MAX_ARGS];

	while (1)
	{
	printer("simple_shell($) ");
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
	parser(command, tokenized," ");
	if (feof(stdin))
        {
	free(command);
	printer("Exit succeed:");
        break;
        }
	/*execute command*/
	if ((conditions(tokenized)) != 0)
		executer(tokenized);
	}
	free(command);
	return (0);
}
/**
 * conditions - check many conditions before calling executer
 * @command: tokenized command or user input
 * Return: 1 if there is no conditions, if any 0
 */
int conditions(char *tokenized[MAX_ARGS])
{
        if (_strcmp(tokenized[0],"env") == 0)
        {
        /*my_env();*/
        return (0);
        }
        else if (_strcmp(tokenized[0],"exit") == 0)
        {
        /*my_exit();*/
        return (0);
        }
        return (1);
}
/**
 * executer - recieve tokenized argument and excute them from PATH file
 * @tokenized: the tokenized array of arguments
 * Return: -1 on error and 0 on success
 */
void executer(char *tokenized[MAX_ARGS])
{
        pid_t pid = 0;
        char *ab_path = NULL;

        /*path is checked if it exist and executable by get_path, else return NULL*/
        ab_path = get_path(tokenized[0]);
        if (ab_path == NULL)
        {
        perror("File Not found");
        }
        else
        {
        pid = fork();
        }
        /*Fork create child process with return 0*/
        if (pid == 0)
        {
        execve(ab_path, tokenized, NULL);
        }
        else if (pid > 0)
        {
        wait(NULL);
        free(ab_path);
        }
        else
        {
        perror("Error in fork");
        }
}
/**
 * get_path - recive tokenized "PATH" and check path exist and return it
 * @file: the string to contacenate on path or file name
 * Return: existed and executable file path
 */
char *get_path(char *file)
{
        char *path = NULL;
        char *tok_copy;

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
/**
 * parser - parse the string using delimiter space in argument
 * @command: the string
 * @delim: delimeter to parsing or tokenizing
 * Return: 0 success
 */
void parser(char *command, char *args[MAX_ARGS], char *delim)
{
        char *token;
        int argc = 0;

        token = strtok(command, delim);
        while (token != NULL)
        {
        args[argc] = token;
        token = strtok(NULL, delim);
	argc++;
        }
	args[argc] = NULL;
}
/**
 * printer - print the str
 * @str: the string
 * Return: number of print
 */
int printer(char *str)
{
        int count = 0;

        while (str[count])
        {
        _putchar(str[count]);
        count++;
        }
        return (count);
}
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
        return (write(1, &c, 1));
}
/**
 * _strlen - return the lenght of string
 * @str: the string
 * Return: the len
 */
int _strlen(char *str)
{
        int count = 0;

        while (str[count])
                count++;
        return (count);
}
/**
 * _strcat - concatenates src on dest string
 * @dest: the destination string
 * @src: the source string
 * Return: pointer to dest
 */
char *_strcat(char *dest, char *src)
{
        int x, y;

        x = 0;
        while (dest[x])
        {
        x++;
        }
        for (y = 0; src[y]; y++)
        {
        dest[x] = src[y];
        x++;
        }
        dest[x] = '\0';
        return (dest);
}
/**
 * _strcmp - compares two strings and return
 * @s1: string one
 * @s2: string two
 * Return: result
 */
int _strcmp(char *s1, char *s2)
{
        int x, y = 0;

        for (x = 0; s1[x] && s2[x]; x++)
        {
        y = s1[x] - s2[x];
        if (y != 0)
        {
        return (y);
        }
        }
        return (0);
}
/**
 * _strcpy - copy the string from src to dest
 * @src: source of string
 * @dest: destination of string
 * Return: pointer of dest
 */
char *_strcpy(char *dest, char *src)
{
        int x;

        for (x = 0; src[x]; x++)
        {
        dest[x] = src[x];
        }
        dest[x] = '\0';
        return (dest);
}
