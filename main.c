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
		execution(incmd);
		arguments_exec(incmd);
        }
	return (0);
}
