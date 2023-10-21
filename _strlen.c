#include "main.h"

/**
  * _strlen - return the len of str
  * @str: str
  * Return: len of the str.
  */
int _strlen(char *str)
{
	int j = 0;

	if (!str)
		return (-1);
	while (str[j])
		j++;
	return (j);
}
