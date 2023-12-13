#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * _strtok - Custom implementation of strtok
 * @str: The string to tokenize
 * @delimiters: The delimiter characters
 *
 * Return: Pointer to the next token, or NULL if no more tokens are found
 */

char *_strtok(char *str, const char *delimiters) {
    static char *next_token; // Stores the pointer to the next token

    // If str is NULL, continue tokenizing from the previous position
    if (str == NULL) {
        str = next_token;
    }

    // Skip leading delimiters
    str += strspn(str, delimiters);

    // If the current position is at the end of the string, return NULL
    if (*str == '\0') {
        return NULL;
    }

    // Find the end of the token
    char *token_end = str + strcspn(str, delimiters);

    // If the token is not empty, terminate it and update next_token
    if (*token_end != '\0') {
        *token_end = '\0';
        next_token = token_end + 1;
    } else {
        next_token = token_end;
    }

    return str;
}

/**
 * main - Entry point
 *
 * Return: Always 0
 */

int main() {
    char input_line[100];  // Assuming a maximum command length of 100 characters
    char delimiters[] = " "; // Delimiters: space

    printf("Enter a command: ");
    fgets(input_line, sizeof(input_line), stdin);

    // Remove the newline character, if present
    if (input_line[strlen(input_line) - 1] == '\n') {
        input_line[strlen(input_line) - 1] = '\0';
    }

    char *token = _strtok(input_line, delimiters);
    while (token != NULL) {
        printf("Token: %s\n", token);
        token = _strtok(NULL, delimiters);
    }

    return 0;
}
