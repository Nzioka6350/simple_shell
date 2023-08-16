#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>

#define MAX_TOKENS 100
#define PATH_MAX_LENGTH 1024

void execution(char **argv);
char *get_location(char *command);

#define INPUT_LENGTH 100
int exiting(void);
#endif 
