#include <unistd.h>

/**
 * _putchar - writes the character
 * @c: char to be printed
 * @file_no: file discriptor.
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c, int file_no)
{
	return (write(file_no, &c, 1));
}
