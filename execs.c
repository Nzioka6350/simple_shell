#include "shell.h"
/**
 *execute_command - a function that executes shell commands
 *@command: command to be executed
 *Return: returns 0 if successful
 */
void execute_command(char *command)
{
	pid_t pid;
	char *envp[] = {NULL};

	pid = fork();
	if (pid < 0)
	{
		perror("fork failed");
		exit(1);
	}
	else if (pid == 0)
	{
		char *args[MAX_ARGS];
		int argc = 0;

		char *token = strtok(command, " ");

		while (token != NULL && argc < MAX_ARGS - 1)
		{
			args[argc] = token;
			argc++;
			token = strtok(NULL, " ");
		}
		args[argc] = NULL;
		if (execve(args[0], args, envp) == -1)
		{
			perror("execution failed");
			exit(1);
		}
	}
	else
	{
		int status;

		wait(&status);
	}
}
