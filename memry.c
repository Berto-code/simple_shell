#include "shell.h"

/**
 * _realloc - Reallocates a memory block using malloc and free
 *
 * @ptr: Pointer to the memory previously allocated
 * @old_size: Size, in bytes, of the allocated space for ptr
 * @new_size: New size, in bytes of the new memory block
 *
 * Return: reallocated memory(n)
 **/
void *_realloc(void *ptr, size_t old_size, size_t new_size)
{
	char *n, *aux;
	unsigned int b;

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
	{
		n = malloc(new_size);
		if (n == NULL)
			return (NULL);

		return (n);
	}

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	n = malloc(new_size);
	if (n == NULL)
		return (NULL);

	aux = ptr;
	for (a = 0; a < old_size; a++)
		n[b] = aux[b];

	free(ptr);

	return (n);
}
