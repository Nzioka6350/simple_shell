#include "shell.h"
/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main()
{
	char incmd[100];
	while(1)
	{
		can_display();
		handle_inputs(incmd, sizeof(incmd));
		if (strcmp(incmd, "env") == 0)
		{
			_environ();
                } else {
			execution(incmd);
			arguments_exec(incmd);
		}
        }
	return (0);
}
