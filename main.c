#include "shell.h"

/**
 * main - Check the code
 *
 * Return: Always 0.
 */
int main(void)
{
		char incmd[100];
		char *insert;
		char inpcmd[MAX_COMMAND_LENGTH];
		char args[MAX_COMMAND_LENGTH];

		while (1)
		{
			can_display();
			handle_inputs(incmd, sizeof(incmd));

			if (strcmp(incmd, "exit") == 0)
			{
				buldin_exiting();
			}
			else if (strcmp(incmd, "env") == 0)
			{
				_environ();
			}
			else
			{
				execution(incmd);
				arguments_exec(incmd);
			}

			shell_print("Enter anything:");
			insert = ourOwn_shellgetline();

			tokenize_cmd(insert, inpcmd, args);
			printf("First Word or Command: %s\n", inpcmd);
			printf("Arguments: %s\n", args);

			free(insert);

			if (strncmp(inpcmd, "setenv ", 7) == 0)
			{
				char *token = strtok(args, " ");
				if (token != NULL)
				{
					setenv(token, args + strlen(token) + 1, 1);
				}
				else
				{
					fprintf(stderr, "Usage: setenv VARIABLE VALUE\n");
				}
			}
			else if (strncmp(inpcmd, "unsetenv ", 9) == 0)
			{
				char *variable = args + 9;
				if (*variable != '\0')
				{
					unsetenv(variable);
				}
				else
				{
					fprintf(stderr, "Usage: unsetenv VARIABLE\n");
				}
			}
		}

		return (0);
}
