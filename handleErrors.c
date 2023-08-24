#include "shell.h"
/**
 * Inputs - Print a string to the standard error stream.
 * @str: The string to be printed.
 *
 * This function is used to print a given string to the standard error stream.
 * The provided @str parameter represents the string to be printed.
 * The function doesn't return a specific value;
 * it simply outputs the string to the error stream.
 *
 * Return: Nothing.
 */
void Inputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		put_char(str[i]);
		i++;
	}
}
/**
 * _eputchar - Write a character to the standard error stream.
 * @c: The character to be printed.
 *
 * This function is used to write a specified character to
 * the standard error stream.
 * The provided @c parameter represents the character to be printed.
 * On success, the function returns 1.
 * On error, -1 is returned, and the `errno`
 * variable is set appropriately to indicate the specific error.
 *
 * Return: On success, 1. On error, -1 is returned, and `errno` is set.
 */
int put_char(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}
/**
 * ftputs - Write a character to a specified file descriptor.
 * @c: The character to be written.
 * @fd: The file descriptor to write to.
 *
 * This function is used to write a specified character to
 * the given file descriptor.
 * The provided @c parameter represents the character to be written,
 * and the @fd parameter specifies the file descriptor to write to.
 * On success,the function returns 1.
 * On error, -1 is returned, and the `errno` variable is
 * set appropriately to indicate the specific error.
 *
 * Return: On success, 1. On error, -1 is returned, and `errno` is set.
 */
int ftputs(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}
/**
 * place - Write a string to a specified file descriptor.
 * @str: The string to be written.
 * @fd: The file descriptor to write to.
 *
 * This function is used to write a given string to the specified file
 * descriptor. The provided @str parameter represents the string to be written,
 * and the @fd parameter specifies the file descriptor to write to.
 * The function returns the number of characters successfully written to
 * the file descriptor.
 *
 * Return: The number of characters written on success.
 *         On error, -1 is returned, and `errno` is set appropriately.
 */
int place(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += ftputs(*str++, fd);
	}
	return (i);
}
