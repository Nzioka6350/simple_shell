#include "shell.h"
/**
 * shell_print - Our own printf.
 * @Inputs: Command typed.
 *
 * Return: Always 0.
 */
void shell_print(const char *Inputs)
{
	write(STDOUT_FILENO, Inputs, strlen(Inputs));
}
