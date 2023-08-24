#include "shell.h"

int main(void)
{
	char incmd[100];
	
	while (1)
	{
		can_display();
		handle_inputs(incmd, sizeof(incmd));
		execution(incmd);
		arguments_exec(incmd);
	}

	return (0);
}
