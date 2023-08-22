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
