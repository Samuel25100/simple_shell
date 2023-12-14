#include "shell.h"
/**
 * my_calloc - return initalized memory
 * @num_el: number of element
 * @size_el: size of each element
 * Return: pointer to mem
 */
void *my_calloc(size_t num_el, size_t size_el)
{
	size_t tot = num_el * size_el;
	void *ptr = NULL;

	if (num_el != 0 && tot / num_el != size_el)
	{
	return (NULL);
	}
	ptr = malloc(tot);
	if (ptr != NULL)
	{
	_memset(ptr, 0, tot);
	}
	return (ptr);
}
