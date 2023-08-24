#include "shell.h"
/**
 * clear_info - Initialize an info_t struct.
 * @info: Pointer to the struct to be initialized.
 *
 * This function is used to initialize an `info_t` struct by setting its
 * members to appropriate initial values. The provided @info parameter points
 * to the address of the struct to be initialized. After calling this function,
 * the struct will be ready to store and manage information related
 * to the shell's command execution.
 *
 * Return: None.
 */
void clear_info(info_t *info)
{
	info->arg = NULL;
	info->argv = NULL;
	info->path = NULL;
	info->argc = 0;
}
/**
 * set_info - Initialize an info_t struct with provided argument vector.
 * @info: Pointer to the struct to be initialized.
 * @av: Argument vector containing command and arguments.
 *
 * This function is used to initialize an `info_t`
 * struct by setting its
 * members to appropriate initial values
 * and populating it with information
 * from the provided argument vector.
 * The @info parameter points to the address of the struct to
 * be initialized, and the @av parameter represents the argument
 * vector containing the command and its arguments.
 *
 * Return: None.
 */
void set_info(info_t *info, char **av)
{
	int i = 0;

	info->fname = av[0];
	if (info->arg)
	{
		info->argv = strtow(info->arg, " \t");
		if (!info->argv)
		{

			info->argv = malloc(sizeof(char *) * 2);
			if (info->argv)
			{
				info->argv[0] = _strdup(info->arg);
				info->argv[1] = NULL;
			}
		}
		for (i = 0; info->argv && info->argv[i]; i++)
			;
		info->argc = i;

		replace_alias(info);
		replace_vars(info);
	}
}
/**
 * free_info - Free memory associated with the fields of an info_t struct.
 * @info: Pointer to the struct whose fields need to be freed.
 * @all: Boolean indicating whether to free all fields.
 *
 * This function is used to free memory associated with the
 * fields of an `info_t` struct.
 * The @info parameter points to the address of the
 * struct whose fields are to be freed.
 * The @all parameter is a boolean value that determines whether
 * to free all fields or a subset of them.
 *
 * If @all is true, the function frees memory associated with all fields.
 * If @all is false, only specific fields are freed.
 *
 * Return: None.
 */
void free_info(info_t *info, int all)
{
	ffree(info->argv);
	info->argv = NULL;
	info->path = NULL;
	if (all)
	{
		if (!info->cmd_buf)
			free(info->arg);
		if (info->env)
			free_list(&(info->env));
		if (info->history)
			free_list(&(info->history));
		if (info->alias)
			free_list(&(info->alias));
		ffree(info->environ);
			info->environ = NULL;
		bfree((void **)info->cmd_buf);
		if (info->readfd > 2)
			close(info->readfd);
		_putchar(BUF_FLUSH);
	}
}
