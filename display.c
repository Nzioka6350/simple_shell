#include "shell.h"

/**
 *  _prerror - Print Custome Error
 * @argv:Program Name
 * @c:Error Count
 * @cmd:Command
 * This function is responsible for printing a custom
 * error message to the standard output.
 * It prints an error message indicating that
 * an illegal number was provided as an argument.
 *  @argv: The name of the program that encountered the error.
 * @c: The error count or index, typically used to track
 * the number of commands executed.
 * @cmd: The command that caused the error, along with its arguments
 * Return: Void
 */
void _prerror(char **argv, int c, char **cmd)
{
	char *er = _itoa(c);

	PRINTER(argv[0]);
	PRINTER(": ");
	PRINTER(er);
	PRINTER(": ");
	PRINTER(cmd[0]);
	PRINTER(": Illegal number: ");
	PRINTER(cmd[1]);
	PRINTER("\n");
	free(er);
}
