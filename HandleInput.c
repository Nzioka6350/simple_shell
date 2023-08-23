#include "shell.h"
/**
 * handle_inputs- Function that handles user inputs,commands and EOF.
 *
 * @incmd: command typed
 * @size: Allocated size
 *
 * Return: Always 0.
 */
void handle_inputs(char *incmd, size_t size)
{
	if (fgets(incmd, size, stdin) == NULL)
	{
		if (feof(stdin))
		{
			shell_print("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("There is an error");
			exit(EXIT_FAILURE);
		}
	}
	incmd[strcspn(incmd, "\n")] = '\0';
}
