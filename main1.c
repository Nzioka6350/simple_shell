#include "shell.h"

/**
 * main - Check the code
 *
 * Return: Always 0.
 */
int main()
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
		}
		return (0);
}
