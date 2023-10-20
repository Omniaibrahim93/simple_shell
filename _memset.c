#include "main.h"

/**
  * _memset - fills memory withconstant byte.
  * @sa: memory area to fill
  * @by: constant byte to fill with
  * @n1: first n bytes to be filled
  * Return: pointer to memory area s
  */
char *_memset(char *sa, char by, unsigned int n1)
{
	char *string = sa;
	unsigned int j;

	for (j = 0; j < n1; j++)
	{
		*(string + j) = by;
	}
	return (sa);
}
