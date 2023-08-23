#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LENGTH 1024

void parse(char *line, char **args);
void execute(char **args);

int main(void)
{
	char *line;
	char *args[MAX_LENGTH / 2 + 1];
	int should_run = 1;

	while (should_run)
	{
		printf("simple_shell> ");
		fflush(stdout);

		line = malloc(MAX_LENGTH);
		fgets(line, MAX_LENGTH, stdin);

		parse(line, args);
		execute(args);

		free(line);
	}

	return 0;
}

void parse(char *line, char **args)
{
	int i = 0;
	args[i] = strtok(line, " \n");
	while (args[i] != NULL)
	{
		i++;
		args[i] = strtok(NULL, " \n");
	}
}

void execute(char **args)
{
	pid_t pid = fork();
	if (pid == 0)
	{
		execvp(args[0], args);
		printf("Unknown command: %s\n", args[0]);
		exit(1);
	}
	else if (pid < 0)
	{
		printf("Fork failed.\n");
		exit(1);
	}
	else
	{
		wait(NULL);
	}
}
