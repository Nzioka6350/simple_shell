#include "shell.h"

/**
 * is_interactive - checks if the shell is in interactive mode
 * @info: pointer to the info_t struct
 *
 * This function checks whether the shell is running in interactive mode by
 * examining the file descriptors of the standard input and the read file
 * descriptor of the info_t struct.
 *
 * Return: 1 if the shell is in interactive mode, 0 otherwise
 */
int is_interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delimiter - checks if a character is a delimiter
 * @c: the character to check
 * @delimiter: the delimiter string
 *
 * The function checks if a given charter is present in the delim string.
 *
 * Return: 1 if the character is a delimiter, 0 otherwise
 */
int is_delimiter(char c, char *delimiter)
{
	while (*delimiter)
		if (*delimiter++ == c)
			return (1);
	return (0);
}

/**
 * _isalpha - checks for an alphabetic character
 * @c: the character to check
 *
 * This function checks whether the given character is an alphabetic character.
 *
 * Return: 1 if the character is alphabetic, 0 otherwise
 */
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - converts a string to an integer
 * @str: the string to be converted
 *
 * This function converts a string representation of an integer to an integer.
 *
 * Return: 0 if no numbers in string, the converted number otherwise
 */
int _atoi(char *str)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0;  str[i] != '\0' && flag != 2; i++)
	{
		if (str[i] == '-')
			sign *= -1;

		if (str[i] >= '0' && str[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (str[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
