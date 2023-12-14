#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1024

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
        if (lineptr == NULL || n == NULL || stream == NULL)
                return (-1); /* Invalid arguments */

        char *buffer = malloc(MAX_LINE_LENGTH);

        if (buffer == NULL)
                return (-1); /* Memory allocation failed */

        size_t i = 0;
        int c;

        while ((c = fgetc(stream)) != EOF && c != '\n')
        {
                if (i < MAX_LINE_LENGTH - 1)
                        buffer[i++] = c;
                else
                {
                        /* Line exceeds buffer size, handle error or truncate line */
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

/**
 * main - Entry point of the program
 *
 * Return: 0 on success
 */

int main(void)
{
        char *line = NULL;
        size_t size = 0;
        ssize_t length;

        printf("Enter a line of text: ");
        length = _getline(&line, &size, stdin);

        if (length != -1)
        {
                printf("Line: %s\n", line);
                printf("Length: %zd\n", length);
        }
        else
        {
                printf("Error reading line.\n");
        }

        free(line);

        return (0);
}
