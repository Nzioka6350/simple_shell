#include "shell.h"
/**
 * execution - Function that handles the arguments.
 * @incmd: Command typed.
 *
 * Return: Always 0.
 */
void execution(const char *incmd)
{
	pid_t child_pid = fork();
	char *envir[] = {
		"PATH=/usr/bin:/bin",
		NULL
	};

	if (child_pid == -1)
	{
		perror("Fork error:");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		char *args[2];

		args[0] = (char *)incmd;
		args[1] = NULL;

		if (execve(incmd, args, envir) == -1)
		{
			perror("Error occurred:");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(NULL);
	}
}
