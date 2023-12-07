#ifndef SHELL_H
#define SHELL_H
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
char **parser(char *str, char *delim);
void executer(char **command);
char *get_path(char *file);
#endif
