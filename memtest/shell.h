#ifndef SHELL_H
#define SHELL_H
#define MAX_ARGS 10
#define MAX_COM 1024
/*Headers*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

/*Functions*/
int _strlen(char *str);
char *_strdup(char *str);
int _putchar(char c);
int printer(char *str);
void parser(char *str, char *args[MAX_ARGS], char *delim);
void executer(char *tokenized[MAX_ARGS]);
char *get_path(char *file);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int conditions(char **command);
int _strcmp(char *s1, char *s2);
char *add_command(char *path, char *token);
void my_env(void);
#endif
