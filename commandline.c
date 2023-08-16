#include "shell.h"

void execution(char **argv)
{
        char *command = NULL;

	if (argv)
	{
		command = argv[0];

		if (execve(command, argv, NULL) == -1)
		{
			perror("There is an Error");
		}
	}
}
