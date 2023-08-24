#include "shell.h"

/**
 * get_environ - Return a copy of the string array containing the environment.
 * @info: Pointer to a structure containing potential arguments.
 *
 * This function is used to create and return a copy of the string array that
 * represents the environment variables. The provided @info parameter is used
 * to maintain a consistent function prototype.
 *
 * The function doesn't modify the environment or the input parameters. It
 * returns 0 to indicate successful completion.
 *
 * Return: Always 0.
 */
char **get_environ(info_t *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = list_to_strings(info->env);
		info->env_changed = 0;
	}

	return (info->environ);
}
/**
 * _unsetenv - Remove an environment variable.
 * @info: Pointer to a structure containing potential arguments.
 * @var: The string representing the environment variable to remove.
 *
 * This function is used to remove an environment variable
 * from the environment.
 * The provided @info parameter is used to maintain a
 * consistent function prototype.
 * The @var parameter specifies the string
 * representing the environment variable to be removed.
 * If the removal is successful, the function returns 1.
 * f the specified environment variable doesn't exist
 * or an error occurs during removal, the function returns 0.
 *
 * Return: 1 on successful removal, 0 otherwise.
 */
int _unsetenv(info_t *info, char *var)
{
	list_t *node = info->env;
	size_t i = 0;
	char *z;

	if (!node || !var)
		return (0);

	while (node)
	{
		z = starts_with(node->str, var);
		if (z && *z == '=')
		{
			info->env_changed = delete_node_at_index(&(info->env), i);
			i = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		i++;
	}
	return (info->env_changed);
}
/**
 * _setenv - Initialize a new environment variable or modify an existing one.
 * @info: Pointer to a structure containing potential arguments.
 * @var: The string representing the environment variable property.
 * @value: The string representing the environment variable value.
 *
 * This function is used to initialize a new environment variable or
 * modify an existing one.
 * The provided @info parameter is used to maintain a consistent
 * function prototype.
 * The @var parameter specifies the string representing the
 * environment variable property to be set or modified,
 * and the @value parameter specifies the value
 * to assign to the environment variable.
 *
 * The function doesn't modify the environment or the input parameters.
 * It returns 0 to indicate successful completion.
 *
 * Return: Always 0.
 */
int _setenv(info_t *info, char *var, char *value)
{
	char *buff = NULL;
	list_t *node;
	char *w;

	if (!var || !value)
		return (0);

	buff = malloc(_strlen(var) + _strlen(value) + 2);
	if (!buff)
		return (1);
	_strcpy(buff, var);
	_strcat(buff, "=");
	_strcat(buff, value);
	node = info->env;
	while (node)
	{
		w = starts_with(node->str, var);
		if (w && *w == '=')
		{
			free(node->str);
			node->str = buff;
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(info->env), buff, 0);
	free(buff);
	info->env_changed = 1;
	return (0);
}
