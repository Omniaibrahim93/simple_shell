#include "main.h"

/**
  * _realloc - realloc memory size.
  * @ptr: old ptr.
  * @size: new size.
  * Return: a pointer to the newly allocated memeory.
  */
void *_realloc(void *ptr, size_t size)
{
	void *newe_ptr = malloc(size);

	if (newe_ptr == NULL)
	{
		return (NULL);
	}
	_memcpy(newe_ptr, ptr, size);
	free(ptr);
	return (newe_ptr);
}
