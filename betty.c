#include <stdio.h>

/**
 * betty - check which number is the greatest
 *
 * Return: Always returs 0.
 */

int betty(void)
{
	int j, k;

	printf("Enter j:\n");
	scanf("%d ", &j);
	printf("Enter k:\n");
	scanf("%d ", &k);

	if (j > k)
	{
		printf("J is the largest\n");
	}
	else
	{
		printf("K is the largest\n");
	}
	return (0);
}
