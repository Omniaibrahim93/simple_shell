#include "main.h"

/**
  * _strncpy - copiess str.
  * @dest: dest str.
  * @src: src str
  * @n: num of bytes from src to be copied
  * Return: dest add
  */
char *_strncpy(char *dest, char *src, int n)
{
	int j = 0;

	for (j = 0; j < n && src[j] != '\0'; j++)
		dest[j] = src[j];
	for ( ; j < n; j++)
		dest[j] = '\0';

	return (dest);
}
