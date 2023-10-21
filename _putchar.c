#include <unistd.h>

/**
 * _putchar - writes the char c to stdout
 * @ch: The character to be printed
 * @file_no: file discriptor.
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char ch, int file_no)
{
	return (write(file_no, &ch, 1));
}
