#include "shell.h"
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
	print_error(tokenized, "File Not found");
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
	else if (pid < 0)
	{
	print_error(tokenized, "Error in fork");
	}
}
