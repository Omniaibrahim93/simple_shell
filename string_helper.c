#include "shell.h"

/**
 * _strlen - returns the length of a string.
 * @string: pointer to string.
 * Return: length of string.
 */
int _strlen(char *string)
{
	int length = 0;

	if (string == NULL)
		return (0);

	while (string[length++] != '\0')
	{
	}
	return (--length);
}
