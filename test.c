#include "shell.h"

int main(void)
{
    char command[MAX_COMMAND_LENGTH];
	
    int status;
    int ret;
    pid_t pid;
    while (1)
    {
        printf("simple_shell> ");

        if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL)
        {
            printf("\nExiting shell...\n");
            break;
        }

        command[strcspn(command, "\n")] = '\0';
	pid = fork();
        if (pid == -1)
        {
            perror("Fork error");
        }
        else if (pid == 0)
        {
        	ret = execlp(command, command, NULL);

          if (ret == -1)
            {
                fprintf(stderr, "Error: Command not found\n");
                exit(EXIT_FAILURE);
            }
        }
        else
        {
         waitpid(pid, &status, 0);
        }
    }

    return 0;
}
