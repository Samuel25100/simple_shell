#include <stdio.h>
#include <stdlib.h>

/**
 * _getline - Read a line of input from the user
 *
 * Return: Pointer to the input line, or NULL on failure
 */

char *_getline() {
    char *line = NULL;
    size_t line_size = 0;
    ssize_t chars_read;
    size_t current_size = 0;

    while ((chars_read = getline(&line, &line_size, stdin)) != -1) {
        current_size += chars_read;

        // Check if the line is complete (ends with a newline)
        if (line[chars_read - 1] == '\n') {
            // Remove the newline character
            line[chars_read - 1] = '\0';
            break;
        }

        // Resize the buffer to accommodate more input
        char *temp = realloc(line, current_size + line_size);
        if (temp == NULL) {
            fprintf(stderr, "Memory reallocation failed\n");
            free(line);
            return NULL;
        }
        line = temp;
    }

    return line;
}

/**
 * main - Entry point
 *
 * Return: Always 0
 */

int main() {
    printf("Enter a line: ");
    fflush(stdout);

    char *line = _getline();
    if (line != NULL) {
        printf("Input: %s\n", line);
        free(line);
    }

    return 0;
}
