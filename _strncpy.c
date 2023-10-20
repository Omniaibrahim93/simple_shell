#include "main.h"

/**
  * _stringncpy - copies a string.
  * @dst: destnation string
  * @src: source string
  * @bn: number of bytes from src to be copied
  * Return: destnation address
  */
char *_stringncpy(char *dst, char *src, int bn)
{
	int j = 0;

	for (j = 0; j < bn && src[j] != '\0'; j++)
		dst[j] = src[j];
	for ( ; j < bn; j++)
		dst[j] = '\0';

	return (dst);
}
