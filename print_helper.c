#include "shell.h"

/**
 * _print - Writes an array of chars to standard output.
 * @string: Pointer to the array of chars.
 * Return: The number of bytes written.
 * On error, -1 is returned.
 */
int _print(char *string)
{
    return (write(STDOUT_FILENO, string, _strlen(string)));
}

/**
 * _printe - Writes an array of chars to standard error.
 * @string: Pointer to the array of chars.
 * Return: The number of bytes written.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _printe(char *string)
{
    return (write(STDERR_FILENO, string, _strlen(string)));
}
