#include "shell.h"
/**
 * handle_error - Convert a string to an integer.
 * @s: The string to be converted.
 *
 * This function is used to convert a given string to an integer. The provided
 * @s parameter represents the string to be converted. If the string contains
 * no numbers, the function returns 0. If the conversion is successful, the
 * function returns the converted number. On error, -1 is returned.
 *
 * Return: 0 if no numbers are found in the string.
 *         The converted number on success.
 *         -1 on error.
 */
int handle_error(char *s)
{
	int i = 0;
	unsigned long int res = 0;

	if (*s == '+')
		s++;
	for (i = 0;  s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			res *= 10;
			res += (s[i] - '0');
			if (res > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (res);
}
/**
 * err_ptr - Print an error message with additional information.
 * @info: Pointer to a structure containing parameter and return information.
 * @estr: String containing the specified error type.
 *
 * This function is used to print an error message with additional information.
 * The provided @info parameter points to a structure that contains relevant
 * information about parameters and return values. The @estr parameter is a
 * string that specifies the type of error that occurred.
 *
 * The function doesn't return specific values; it primarily serves to display
 * error messages.
 *
 * Return: None.
 */
void err_ptr(info_t *info, char *estr)
{
	Inputs(info->fname);
	Inputs(": ");
	dprint(info->line_count, STDERR_FILENO);
	Inputs(": ");
	Inputs(info->argv[0]);
	Inputs(": ");
	Inputs(estr);
}
/**
 * dprint - Print a decimal (integer) number (base 10).
 * @input: The integer number to be printed.
 * @fd: The file descriptor to write to.
 *
 * This function is used to print a decimal (integer) number in base 10.
 * The provided @input parameter represents the integer number to be printed.
 * The @fd parameter specifies the file descriptor to write to. The function
 * returns the number of characters successfully printed.
 *
 * Return: The number of characters printed on success.
 */
int dprint(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int i, count = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (_abs_ / i)
		{
			__putchar('0' + current / i);
			count++;
		}
		current %= i;
	}
	__putchar('0' + current);
	count++;

	return (count);
}
/**
 * num_conv - Convert a number to a string representation in a given base.
 * @num: The number to be converted.
 * @base: The base for conversion.
 * @flags: Argument flags.
 *
 * This function is used to convert a given number to a string representation
 * in the specified base. The @num parameter represents the number to be
 * converted, @base indicates the base for conversion (
 * e.g., decimal or binary) and @flags are additional argument flags.
 *
 * The function returns a string containing the converted number.
 *
 * Return: A string representing the converted number.
 */
char *num_conv(long int num, int base, int flags)
{
	static char *arr;
	static char buff[50];
	char sign = 0;
	char *ltr;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';

	}
	arr = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ltr = &buff[49];
	*ltr = '\0';

	do	{
		*--ltr = arr[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ltr = sign;
	return (ltr);
}
/**
 * rm_comm - Replace the first instance of '#' with '\0' in a string.
 * @buf: Address of the string to be modified.
 *
 * This is used to modify a given string by replacing the first instance
 * of the '#' character with the null-terminating character '\0'.The provided
 * @buf parameter points to the address of the string to be modified.
 * The function always returns 0 to indicate completion.
 *
 * Return: Always 0.
 */
void rm_comm(char *buf)
{
	int i;

	for (i = 0; buf[i] != '\0'; i++)
		if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
		{
			buf[i] = '\0';
			break;
		}
}
