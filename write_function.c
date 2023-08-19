#include "shell.h"

void shell_print(const char *Inputs)
{
	write(STDOUT_FILENO,Inputs, strlen(Inputs));
}
