#include "main.h"

/**
  * _memcpy - copies memory area.
  * @dst: destnation buffer
  * @src: buffer to copy from
  * @b: number of bytes to copy
  * Return: pointer to dest
  */
char *_memcpy(char *dst, char *src, unsigned int b)
{
	unsigned int j;

	for (j = 0; j < b; j++)
	{
		*(dst + j) = src[j];
	}
	return (dst);
}
