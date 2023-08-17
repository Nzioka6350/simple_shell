#include "shell.h"
void execution(char **argv)
{
    pid_t pid = fork();

    if (pid == 0)
    {
        if (execvp(argv[0], argv) == -1)
        {
            perror("tsh: Command execution failed");
            exit(EXIT_FAILURE);
        }
    }
    else if (pid < 0)
        perror("tsh: Fork failed");
    else
        wait(NULL);
}
