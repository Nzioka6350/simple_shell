#include "shell.h"
/**
 * print_number -Print Unsigned Int Putchar
 * @n: Unisigned Integer
 * This function prints an unsigned integer using
 * the _putchar function.
 * It recursively breaks down the integer into its
 * individual digits and prints them.
 * Return: Void
 */
void print_number(unsigned int n)
{
	unsigned int x = n;

	if ((x / 10) > 0)
		print_number(x / 10);

	_putchar(x % 10 + '0');
}
/**
 * print_number_in -Print Number Putchar
 * @n:Integer
 * This function prints an integer using the _putchar function.
 * If the integer is negative, it prints a minus sign
 * and then handles the absolute value.
 * It recursively breaks down the absolute value into
 * its individual digits and prints them.
 * Return: void
 */
void print_number_in(int n)
{
	unsigned int x = n;

	if (n < 0)
	{
		_putchar('-');
		x = -x;
	}
	if ((x / 10) > 0)
		print_number(x / 10);

	_putchar(x % 10 + '0');
}
