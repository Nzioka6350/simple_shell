#include "shell.h"

void arguments_exec(const char *incmd)
{
	pid_t toto_pid = fork();

	if (toto_pid == -1)
	{
		perror("Fork error");
		exit(EXIT_FAILURE);
	}
	else if (toto_pid == 0)
	{
		char *args[100];
		int no_arguments = 0;

		char *token = strtok((char *)incmd, " ");

		while (token != NULL)
		{
			args[no_arguments++] = token;
			token = strtok(NULL, " ");
		}
		args[no_arguments] = NULL;

		execvp(args[0], args);

		shell_print("Error occurred\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}
