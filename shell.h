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

<<<<<<< HEAD
#define MAX_ENV_VARS 100
#define MAX_TOKENS 100
#define PATH_MAX_LENGTH 1024
#define INPUT_LENGTH 100
=======
/*Buffer sizes are here*/
#define BUFF_SIZE 700
#define MAX_COMMAND_LENGTH 100

/*End of the size declaration make sure you place all of then in-between*/
>>>>>>> d89cd51c35e1c543a197ac5b96ccc1a1a311873e

void execution(const char *incmd);
char *get_location(char *command);
int exiting(int ac, char **argv);
int prompting(int ac, char **argv);
int _larger(void);
void print_env(void);

/*My second prototypes*/
void can_display(void);
void handle_inputs(char *incmd, size_t size);
void shell_print(const char *Inputs);
void execution(const char *incmd);
void arguments_exec(const char *incmd);
void _environ();
void buldin_exiting(void);
<<<<<<< HEAD
void setenv_command(char *variable, char *value);
void unsetenv_command(char *variable);
=======
char *ourOwn_shellgetline(void);
void tokenize_cmd(char *cmdin, char *incmd, char *args);
>>>>>>> d89cd51c35e1c543a197ac5b96ccc1a1a311873e
/*End of the prototypes*/
#endif 
