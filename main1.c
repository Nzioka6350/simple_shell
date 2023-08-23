#include "shell.h"

int main(void)
{
	char incmd[100];

	while (1)
	{
		can_display();
		handle_inputs(incmd, sizeof(incmd));
	}
		return (0);
}
