#include "shell.h"

/**
 * _ourenv - prints the current environment
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *
 * This function prints the current environment by iterating through
 * the linked list of environment variables and displaying them.
 *
 * Return: Always 0
 */
int _ourenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - gets the value of an environment variable
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * @nam: environment variable name
 *
 * This function retrieves the value of a specified environment variable
 * by searching through the linked list of environment variables.
 *
 * Return: The value of the environment variable, or NULL if not found
 */
char *_getenv(info_t *info, const char *nam)
{
	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, nam);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * _oursetenv - Initialize or modify an environment variable
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *
 * This function initializes a new environment variable or modifies an
 * existing one by adding or updating it in the
 * linked list of environment variables.
 *
 * Return: 0 if successful, 1 if incorrect number of arguments
 */
int _oursetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _ourunsetenv - Remove an environment variable
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *
 * This function removes specified environment variables from the linked list.
 *
 * Return: Always 0
 */
int _ourunsetenv(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
		_unsetenv(info, info->argv[i]);

	return (0);
}

/**
 * pop_env_list - populates environment linked list
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *
 * This function populates the linked list of environment variables
 * by copying the existing environment variables from the 'environ' array.
 *
 * Return: Always 0
 */
int pop_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}
