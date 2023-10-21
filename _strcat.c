#include "main.h"

/**
  * _strcat - concatenates 2 strings.
  * @dest: string that will hold appended src
  * @src: string to append
  * Return: address of dest
  */
char *_strcat(char *dest, char *src)
{
	int dest_length = 0, j = 0;
	char *m = dest, *n = src;

	while (*m++ != '\0')
		dest_length++;

	while (*n++ != '\0')
	{
		dest[dest_length + j] = src[j];
		j++;
	}
	dest[dest_length + j] = '\0';

	return (dest);
}
