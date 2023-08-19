#include "shell.h"

void _environ() {
	extern char **environ;
	char **env = environ;
	
	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
}
