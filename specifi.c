#include "main.h"

/**
 * print_c - print char.
 * @c: char to print
 * @file_no: Stream
 * Return: length of the variable or -1
 */
int print_c(char c, int file_no)
{
	return (_putchar(c, file_no));
}

/**
 * print_s - print str
 * @s: string to print
 * @file_no: Stream
 * Return: length of the variable or -1
 */
int print_s(char *s, int file_no)
{
	int j = 0;

	if (s == NULL)
		return (-1);
	while (s[j])
	{
		_putchar(s[j], file_no);
		j++;
	}
	return (j);
}

/**
 * print_d - print int
 * @d: num to print
 * @file_no: Stream
 * Return: length of the variable or -1
 */
int print_d(long d, int file_no)
{
	char *dtos;
	int j = 0;

	dtos = _dtos(d);
	while (dtos[j])
	{
		_putchar(dtos[j], file_no);
		j++;
	}
	free(dtos);
	return (j);
}
