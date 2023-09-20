#ifndef SHELL_H
#define SHELL_H
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
void _strtok(char **arr, char *str);
void _prog2(int ac, char **av, char **envp);
void _prog1(int ac, char **av, char **envp);
void _free(char *string, struct stat *sbuf);
void _execute(char **arguments, char **env);
void array_int(char **arr, int str_size);
void error(int ac, char *string, char **av);
#endif
