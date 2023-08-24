#include "shell.h"

/**
 * prompt - Display Shell Prompt
 * This function is responsible for displaying the
 * shell prompt, typically represented
 * as a "$" symbol, indicating that the shell
 * is ready to accept user input.
 */
void prompt(void)
{
	PRINTER("$ ");
}

/**
 * print_error - Display Error Based on Command and How Many Time Shell Looped
 * @input:User Input
 * @counter:Simple Shell Count Loop
 * @argv:Program Name
 * This function displays an error message
 * when a command is not found.
 * it includes information about the program name,
 * loop counter, and the command that was not found.
 * Return: Void
 */
void print_error(char *input, int counter, char **argv)
{
	char *er;

	PRINTER(argv[0]);
	PRINTER(": ");
	er = _itoa(counter);
	PRINTER(er);
	free(er);
	PRINTER(": ");
	PRINTER(input);
	PRINTER(": not found\n");
}
