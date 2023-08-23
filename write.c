#include "shell.h"
/**
 * shell_print -write function to print output.
 *
 * @Inputs - pointer that holds entered chars.
 * Return: Always 0.
 */
void shell_print(const char *Inputs)
{
	write(STDOUT_FILENO, Inputs, strlen(Inputs));
}
