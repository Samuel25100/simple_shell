#include "shell.h"
/**
 * _getline - Read a line from a file or standard input
 * @lineptr: Pointer to the buffer where the line will be stored
 * @n: Pointer to the size of the buffer
 * @stream: File stream to read from
 *
 * Return: The number of characters read, or -1 on failure or end of file
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	char *buffer = NULL;
	size_t i = 0;
	int c = 0;

	if (lineptr == NULL || n == NULL || stream == NULL)
		return (-1); /* Invalid arguments */

	buffer = my_calloc(1024, sizeof(char));
	if (buffer == NULL)
		return (-1); /* Memory allocation failed */
	while ((c = fgetc(stream)) != EOF && c != '\n')
	{
		if (i < (1024 - 1))
			buffer[i++] = c;
		else
		{
		return (-1); /* Line exceeds buffer size, handle error or truncate line */
		}
	}

	buffer[i] = '\0'; /* Null-terminate the string */
	if (i == 0 && c == EOF)
	{
		free(buffer);
		return (-1); /* No characters read, end of file reached */
	}

	*lineptr = buffer;
	*n = i + 1; /* Include space for the null terminator */

	return (i); /* Return the number of characters read */
}
