#include "main.h"

/**
  * _realloc - realloc mem size.
  * @old_ptr: old pointer.
  * @sze: new size.
  * Return: a pointer to the newly allocated memeory.
  */
void *_realloc(void *old_ptr, size_t sze)
{
	void *new_ptr = malloc(sze);

	if (new_ptr == NULL)
	{
		return (NULL);
	}
	_memcpy(new_ptr, old_ptr, sze);
	free(old_ptr);
	return (new_ptr);
}
