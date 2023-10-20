#include "main.h"

/**
  * _stringcat - concatenates two strings.
  * @dst: string that will hold appended src
  * @src: string to append
  * Return: address of dest
  */
char *_stringcat(char *dst, char *src)
{
	int dest_length = 0, j = 0;
	char *m = dest, *n = src;

	while (*m++ != '\0')
		dest_length++;

	while (*n++ != '\0')
	{
		dst[dest_length + j] = src[j];
		j++;
	}
	dst[dest_length + j] = '\0';

	return (dst);
}
