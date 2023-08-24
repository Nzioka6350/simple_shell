#include "shell.h"

/**
 * bfree - Frees a pointer and sets its address to NULL.
 * @ptr: Address of the pointer to be freed.
 *
 * This function frees the memory allocated
 * for a pointer and sets the pointer's
 * address to NULL. It checks if the pointer is not NULL before freeing it.
 *
 * @ptr: Address of the pointer to be freed.
 *
 * Return: 1 if the memory was freed successfully, otherwise 0.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
