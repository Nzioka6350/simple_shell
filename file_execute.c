#include "shell.h"

/**
 * read_file - Read Command From File
 * @filename:Filename
 * @argv:Program Name
 * This function reads commands from
 * a file specified by `filename`. It reads each
 * line from the file, parses the command,
 * and executes it if necessary. The function
 * terminates when all lines in the file have been processed.
 *
 * @filename: The name of the file to read commands from.
 * @argv: The program name
 * Return: -1 or  0
 */

void read_file(char *filename, char **argv)
{
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	int counter = 0;

	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		exit(EXIT_FAILURE);
	}
	while ((getline(&line, &len, fp)) != -1)
	{
		counter++;
		treat_file(line, counter, fp, argv);

	}
	if (line)
		free(line);
	fclose(fp);
	exit(0);
}

/**
 * treat_file - PARSE Check Command Fork Wait Excute in Line of File
 * @line: Line From A File
 * @counter:Error Counter
 * @fp:File Descriptor
 * @argv:Program Name
 * This function takes a line from a file,
 * parses the command, and executes it if necessary.
 * It handles built-in commands, external commands,
 * and also the "exit" command specific
 * to processing a file.
 *
 * @line: The line read from the file.
 * @counter: The error counter (for error reporting).
 * @fp: The file descriptor of the opened file.
 * @argv: The program name.
 * Return : Excute A line void
 */
void treat_file(char *line, int counter, FILE *fp, char **argv)
{
	char **cmd;
	int st = 0;

	cmd = parse_cmd(line);

		if (_strncmp(cmd[0], "exit", 4) == 0)
		{
			exit_bul_for_file(cmd, line, fp);
		}
		else if (check_builtin(cmd) == 0)
		{
			st = handle_builtin(cmd, st);
			free(cmd);
		}
		else
		{
			st = check_cmd(cmd, line, counter, argv);
			free(cmd);
		}
}

/**
 * exit_bul_for_file - Exit Shell Case Of File
 * @line: Line From A File
 * @cmd: Parsed Command
 * @fd:File Descriptor
 * This function handles the "exit" command when
 * processing a line from a file. If no
 * argument is provided, it exits the program
 * with the current error number. If an
 * argument is provided, it attempts to convert
 * it to an integer and exits with that
 * status code. If the argument is not a valid integer,
 * an error message is printed.
 *
 * @cmd: The parsed command.
 * @line: The line from the file.
 * @fd: The file descriptor of the opened file.
 * Return : Case Of Exit in A File Line
 */
void exit_bul_for_file(char **cmd, char *line, FILE *fd)
{
	int statue, i = 0;

	if (cmd[1] == NULL)
	{
		free(line);
		free(cmd);
		fclose(fd);
		exit(errno);
	}
	while (cmd[1][i])
	{
		if (_isalpha(cmd[1][i++]) < 0)
		{
			perror("illegal number");
		}
	}
	statue = _atoi(cmd[1]);
	free(line);
	free(cmd);
	fclose(fd);
	exit(statue);



}
