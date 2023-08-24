#include "shell.h"
/**
 * hist_y- Display the command history list.
 * @info: Pointer to a structure containing potential arguments.
 *
 * This function displays the history list of previously executed commands.
 * Each command is shown on a separate line, and each line is preceded by
 * a line number starting at 0 and incrementing for each subsequent command.
 *
 * The function doesn't take any arguments and doesn't modify the behavior
 * of the shell or the environment.
 *
 * Return: Always 0.
 */
int hist_y(info_t *info)
{
	print_list(info->history);
	return (0);
}
/**
 * un_nickname - Unset an alias for a string.
 * @info: Pointer to a structure containing potential arguments.
 * @str: The string representing the alias to be unset.
 *
 * This function is used to remove or unset an alias associated with a
 * specified string. The provided @str parameter represents the alias to be
 * removed. If the alias is successfully unset, the function returns 0.
 * If an error occurs during the unsetting process, the function returns 1.
 *
 * Return: Always 0 on success, 1 on error.
 */
int un_nickname(info_t *info, char *str)
{
	char *ct, j;
	int turn;

	ct = _strchr(str, '=');
	if (!ct)
		return (1);
	j = *ct;
	*ct = 0;
	turn = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*ct = j;
	return (turn);
}
/**
 * nickname - Create or modify an alias for a string.
 * @info: Pointer to a structure containing potential arguments.
 * @str: The string representing the alias to be set.
 *
 * This function is used to create or modify an alias for a specified string.
 * The provided @str parameter represents the alias to be associated with the
 * specified string. If the alias is successfully set or updated, the function
 * returns 0. If an error occurs during the process, the function returns 1.
 *
 * Return: Always 0 on success, 1 on error.
 */
int nickname(info_t *info, char *str)
{
	char *n;

	n = _strchr(str, '=');
	if (!n)
		return (1);
	if (!*++n)
		return (un_nickname(info, str));

	un_nickname(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}
/**
 * prt_nickname - Print the content of an alias string.
 * @node: Pointer to an alias node containing the alias string.
 *
 * This function is used to display the content of an alias string stored
 * in an alias node. The provided @node parameter points to the alias node
 * containing the alias string to be printed. If the content is successfully
 * printed, the function returns 0. If an error occurs during the process,
 * the function returns 1.
 *
 * Return: Always 0 on success, 1 on error.
 */
int prt_nickname(list_t *node)
{
	char *m = NULL, *u = NULL;

	if (node)
	{
		m = _strchr(node->str, '=');
		for (u = node->str; u <= m; a++)
			_putchar(*u);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}
/**
 * nicknames - Display or set aliases for commands.
 * @info: Pointer to a structure containing potential arguments.
 *
 * This function mimics the behavior of the `alias` built-in command,
 * which allows users to display or set aliases for commands. If called
 * without arguments, it displays the existing aliases. If called with
 * arguments, it sets or modifies aliases as specified. The provided
 * @info parameter is used to maintain a consistent function prototype.
 *
 * The function doesn't take any direct return values; it simply performs
 * actions based on the provided arguments and input.
 *
 * Return: Always 0.
 */
int nicknames(info_t *info)
{
	int i = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			prt_nickname(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		p = _strchr(info->argv[i], '=');
		if (p)
			nickname(info, info->argv[i]);
		else
			prt_nickname(node_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
}
