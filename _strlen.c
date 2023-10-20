#include "main.h"

/**
  * _stringlen - return the length of str
  * @s: string
  * Return: length of the str.
  */
int _stringlen(char *s)
{
	int j = 0;

	if (!s)
		return (-1);
	while (s[j])
		j++;
	return (j);
}
