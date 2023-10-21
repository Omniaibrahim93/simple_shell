#include "main.h"
#include <stddef.h>

/**
  * _strchr - locates a char in str.
  * @s: search str
  * @c: char to search for
  * Return: ptr to first occu of the c character
  */
char *_strchr(char *s, char c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}
