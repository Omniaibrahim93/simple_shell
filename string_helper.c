#include "shell.h"

/**
 * _strlen - Returns the length of a string.
 * @string: Pointer to the string.
 * Return: Length of the string.
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
