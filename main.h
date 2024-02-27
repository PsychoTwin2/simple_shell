#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <errno.h>

void _prompt(void);
void _prnt(char *text);
void execute_command(char* command);
void read_command(char *command, size_t size);
extern char **environ;

#endif
