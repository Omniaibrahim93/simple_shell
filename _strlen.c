#include "main.h"

/**
  * _strlen - return the length of str
  * @s: string
  * Return: length of the str.
  */
int _strlen(char *s)
{
	int j = 0;

	if (!s)
		return (-1);
	while (s[j])
		j++;
	return (j);
}
