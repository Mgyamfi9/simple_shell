#ifndef SHELL_H
#define SHELL_H
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>
void _write(const char *text);
void _prompt(void);
void _execute(const char *order);
void read_input(char *input, size_t size);
#endif
