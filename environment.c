#include "shell.h"
/**
 * _environ -function that handles the environment variables.
 *
 * Return: returns void.
 */
void _environ(void)
{
	extern char **environ;
	char **env = environ;
	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
}
