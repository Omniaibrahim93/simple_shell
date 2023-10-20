#include "main.h"

/**
 * _stringcpy - func that copies src str to dest.
 * @dst: dest ptr holds the copied string.
 * @src: src ptr to copy from
 * Return: return dest ptr on Success
 */

char *_stringcpy(char *dst, char *src)
{
	int j;
	int len;

	len = _stringlen(src);

	if (!dst || !src)
		return (NULL);
	for (j = 0; j <= len; j++)
	{
		dst[j] = src[j];
	}

	return (dst);
}
