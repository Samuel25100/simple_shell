#include "shell.h"
#define MAX_BUFFER_SIZE 1024
/**
 * _getline - Read a line from a file descriptor
 * @lineptr: Pointer to the line buffer
 * @n: Pointer to the size of the line buffer
 * @fd: File descriptor to read from
 *
 * Return: Length of the read line, or -1 on error or end of file
 */
ssize_t _getline(char **lineptr, size_t *n, int fd)
{
	char buffer[MAX_BUFFER_SIZE], current_char;
	ssize_t bytes_read = 0, i = 0, total_bytes = 0;
	char *line = *lineptr;
	size_t line_size = *n, line_index = 0;

	while (1)
	{
	if (line_index >= line_size - 1)
		{
			break;
		}
	bytes_read = read(fd, buffer, sizeof(buffer));
	if (bytes_read == -1)
	{
	return (-1);
	}
	if (bytes_read == 0)
	{
		break;
	}
	for (i = 0; i < bytes_read; i++)
	{
	current_char = buffer[i];
	line[line_index++] = current_char;
	if (current_char == '\n')
	{
	total_bytes += line_index;
	return (total_bytes);
	}
	if (line_index >= line_size - 1)
	{
		break;
	}
	}
	total_bytes += bytes_read;
	}
	if (line_index == 0)
	{
	return (-1);
	}
	line[line_index] = '\0';
	total_bytes += line_index;
	return (total_bytes);
}
