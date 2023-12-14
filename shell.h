#ifndef SHELL_H
#define SHELL_H
#define MAX_ARGS 10
#define MAX_COM 1024
/*Headers*/
#include <fcntl.h>
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
int parser(char *str, char **args, char *delim);
void executer(char **tokenized, char **env);
char *get_path(char *file);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int conditions(char **command, char **env);
int _strcmp(char *s1, char *s2);
char *add_command(char *path, char *token);
void my_env(char **env);
void my_exit(int status);
void print_error(char **tokenized, char *err);
void _memset(char *str, int fill, int size);
int _atoi(char *s);
void _free_tok(char **tokenized, int MAX);
void clean_newline(char *command);
char *_strtok(char *str, const char *delimiters);
#endif
