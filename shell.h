#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>
#include <stddef.h>

#define MAX_TOKENS 100
#define PATH_MAX_LENGTH 1024
#define INPUT_LENGTH 100

void execution(char **argv);
char *get_location(char *command);
int exiting(int ac, char **argv);
<<<<<<< HEAD
int prompting(int ac, char **argv);
int _larger(void);
=======
void print_env(void);

>>>>>>> 082ed29901366b17e1c00d4e40c08cd03e14ac62
#endif 
