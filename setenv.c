#include "shell.h"
/*
 *
 *
 *
 *
 */
void tokenize_cmd(char *cmdin, char *incmd, char *args)
{
        char *space = strchr(cmdin, ' ');
        if (space != NULL)
        {
                strncpy(incmd, cmdin, space - cmdin);
                incmd[space - cmdin] = '\0';
                strcpy(args, space + 1);
        } else
        {
                strcpy(incmd, cmdin);
                args[0] = '\0';
        }
}
root@0ba2c5c15596:/simple_shell# cat setenv.c
#include "shell.h"

void unsetenv_command(char *variable) {
    if (unsetenv(variable) != 0) {
        fprintf(stderr, "Failed to unset environment variable.\n");
    }
}

void setenv_command(char *variable, char *value) {
    if (setenv(variable, value, 1) != 0) {
        fprintf(stderr, "Failed to set environment variable.\n");
    }
}
