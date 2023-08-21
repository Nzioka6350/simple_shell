#include "shell.h"
/*
 *
 *
 *
 *
 */
void execution(const char *incmd)
{
		pid_t toto_pid = fork();
		char *envir[] = {
				"PATH=/usr/bin:/bin",
				NULL
		};

		if (toto_pid == -1)
		{
				perror("Fork error:");
				exit(EXIT_FAILURE);
		}
		else if (toto_pid == 0)
		{
				char *args[2];
				args[0] = (char *)incmd;
				args[1] = NULL;

				execve(incmd, args, envir);

				perror("Error occurred:");
				exit(EXIT_FAILURE);
		}
		else
		{
				wait(NULL);
		}
}
