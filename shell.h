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
void my_exit(int status, char **av);
void print_error(char **tokenized, char *err);
void _memset(char *str, int fill, int size);
int _atoi(char *s);
void _free_tok(char **tokenized, int MAX);
void clean_newline(char *command);
char *_strtok(char *str, const char *delimiters);
void *my_calloc(size_t num_el, size_t size_el);
void _bringline(char **lineptr, size_t *n, char *buffer, size_t j);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
void _memcpy(void *newptr, const void *ptr, unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size);
#endif
