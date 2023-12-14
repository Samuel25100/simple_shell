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
int parser(char *str, char *args[MAX_ARGS], char *delim);
void executer(char *tokenized[MAX_ARGS]);
char *get_path(char *file);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int conditions(char **command, char **env);
int _strcmp(char *s1, char *s2);
char *add_command(char *path, char *token);
void my_env(char **env);
void my_exit();
void print_error(char *tokenized[MAX_ARGS], char *err);
void _memset(char *str, int fill, int size);
void _memcpy(void *newptr, const void *ptr, unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size);
#endif
