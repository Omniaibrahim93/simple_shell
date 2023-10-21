#include "main.h"

/**
  * _memcpy - cop mem area.
  * @dst: dest buf
  * @src: buf to copy from
  * @nb: num of bytes to copy
  * Return: ptr to dest
  */
char *_memcpy(char *dst, char *src, unsigned int nb)
{
	unsigned int j;

	for (j = 0; j < nb; j++)
	{
		*(dst + j) = src[j];
	}
	return (dst);
}
