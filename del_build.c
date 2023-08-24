#include "shell.h"
/**
 * exit - Terminate the shell or set a custom exit status.
 * @info: Pointer to a structure containing potential arguments.
 *
 * This function is used to exit the shell or set a custom exit status.
 * If @info->argc is greater than 1, the function attempts to convert
 * @info->argv[1] to an integer exit code. If successful, the shell
 * will exit with the specified status. If @info->argv[1] is not a valid
 * integer, an error message is displayed and the exit status will be 2.
 *
 * If @info->argc is 1 (only "exit" command without arguments),
 * the shell will exit with status 0.
 *
 * Return: None. The function exits the shell process if necessary.
 */
int exit(info_t *info)
{
	int if_exit;

	if (info->argv[1])
	{
		if_exit = _erratoi(info->argv[1]);
		if (if_exit == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}
/**
 * changedir - Change the current working directory of the shell process.
 * @info: Pointer to a structure containing potential arguments.
 *
 * This function is used to change the current working directory of the
 * shell process. If @info->argc is greater than 1, the function attempts
 * to change the working directory to the path specified in @info->argv[1].
 * If @info->argv[1] is not provided or if the path doesn't exist, the
 * working directory remains unchanged, and an error message is displayed.
 *
 * If changing the directory is successful, the function returns 0.
 * If any errors occur during directory change, a non-zero value might be
 * returned, and an error message will be displayed.
 *
 * Return: Always 0.
 */
int changedir(info_t *info)
{
	char *ch, *dir, buff[1024];
	int chdir_ret;

	ch = getcwd(buff, 1024);
	if (!ch)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dir = _getenv(info, "HOME=");
		if
			(!dir) = chdir_ret = chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(ch);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		chdir_ret = chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buff, 1024));
	}
	return (0);
}
/**
 * tohlp - Display information about built-in shell commands.
 * @info: Pointer to a structure containing potential arguments.
 *
 * This function provides information about the built-in shell commands
 * and their usage. It displays a list of available commands along with
 * a brief description of each command's purpose and usage syntax.
 *
 * The function doesn't take any arguments and doesn't perform any
 * modifications to the shell's behavior or environment.
 *
 * Return: Always 0.
 */
int tohlp(info_t *info)
{
	char **args;

	args = info->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*args);
	return (0);
}
