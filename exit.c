#include "shell.h"

/**
 * _strncpy - copies a string
 * @dest: the destination string to be copied to
 * @src: the source string
 * @n: the number of characters to copy
 *
 * This function copies the source string to
 * the destination string with a limit of n characters.
 * If the source string is shorter than n,
 * the remaining characters in the destination string will be null-terminated.
 *
 * Return: A pointer to the destination string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int m, j;
	char *s = dest;

	m = 0;
	while (src[m] != '\0' && m < n - 1)
	{
		dest[m] = src[m];
		m++;
	}
	if (m < n)
	{
		j = m;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 * _strncat - concatenates two strings
 * @dest: the first string
 * @src: the second string
 * @n: the maximum number of bytes to use from src
 *
 * This function concatenates the source string
 * to the end of the destination string with a limit of n bytes.
 * If the length of the source string is shorter than n,
 * the resulting concatenated string will be null-terminated.
 *
 * Return: A pointer to the concatenated string
 */
char *_strncat(char *dest, char *src, int n)
{
	int m, j;
	char *s = dest;

	m = 0;
	j = 0;
	while (dest[m] != '\0')
		m++;
	while (src[j] != '\0' && j < n)
	{
		dest[m] = src[j];
		m++;
		j++;
	}
	if (j < n)
		dest[m] = '\0';
	return (s);
}

/**
 * _find_chr - locates a character in a string
 * @s: the string to be searched
 * @c: the character to look for
 *
 * This function searches for the specified character
 * in the string and returns a pointer to the first occurrence of it.
 * If the character is not found, the function returns NULL.
 *
 * Return: A pointer to the character in the string, or NULL if not found
 */
char *_find_chr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
