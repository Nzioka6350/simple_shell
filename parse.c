#include "shell.h"

/**
 * parse_cmd - Parse Line Of Input
 * @input:User Input To Parse
 * This function takes a line of user input and
 * tokenizes it into an array of strings.
 * It uses whitespace and newline characters as
 * delimiters to separate the input into tokens.
 * The tokens are stored in dynamically allocated
 * memory and returned as an array of strings.
 *
 * Return: Array Of strings (token):Simple Shell
 */
char **parse_cmd(char *input)
{
	char **tokens;
	char *token;
	int i, buffsize = BUFSIZE;

	if (input == NULL)
		return (NULL);
	tokens = malloc(sizeof(char *) * buffsize);
	if (!tokens)
	{
		perror("hsh");
		return (NULL);
	}

	token = _strtok(input, "\n ");
	for (i = 0; token; i++)
	{
		tokens[i] = token;
		token = _strtok(NULL, "\n ");
	}
	tokens[i] = NULL;

	return (tokens);
}
