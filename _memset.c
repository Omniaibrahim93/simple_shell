#include "main.h"

/**
  * _memset - fills memory with a constant byte.
  * @str: memory area to fill
  * @b: constant byte to fill with
  * @nf: first n bytes to be filled
  * Return: pointer to memory area s
  */
char *_memset(char *str, char b, unsigned int nf)
{
	char *str1 = str;
	unsigned int j;

	for (j = 0; j < nf; j++)
	{
		*(str1 + j) = b;
	}
	return (str);
}
