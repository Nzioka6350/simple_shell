#include "shell.h"
/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main()
{
	char incmd[100];
	char *insert;
	while(1)
	{
		can_display();
		handle_inputs(incmd, sizeof(incmd));
		if(strcmp(incmd, "exit") ==0)
		{
			buldin_exiting();
		}
		else if (strcmp(incmd, "env") == 0)
		{
			_environ();
                } else {
			execution(incmd);
			arguments_exec(incmd);
		}
		shell_print("Enter anything:");
                insert = ourOwn_shellgetline();

		free(insert);
        }
	return (0);
}
