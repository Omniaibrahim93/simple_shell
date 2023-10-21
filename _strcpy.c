#include "main.h"

/**
 * _strcpy - func that copies src str to dest.
 * @dest: dest string.
 * @src: src ptr to copy from
 * Return: return dest ptr on Success
 */

char *_strcpy(char *dest, char *src)
{
	int j;
	int len;

	len = _strlen(src);

	if (!dest || !src)
		return (NULL);
	for (j = 0; j <= len; j++)
	{
		dest[j] = src[j];
	}

	return (dest);
}
