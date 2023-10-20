#include "main.h"
#include <stddef.h>

/**
  * _strchr - locates char in a str.
  * @str: search string
  * @c: character to search for
  * Return: pointer to first occurence of the c character
  */
char *_strchr(char *str, char c)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == c)
			return ((char *)str);
		str++;
	}
	if (c == '\0')
		return ((char *)str);
	return (NULL);
}
