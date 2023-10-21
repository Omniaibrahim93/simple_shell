#include "main.h"

/**
 * print_c - print char.
 * @ch: char to print
 * @file_no: Stream
 * Return: length of the variable or -1
 */
int print_c(char ch, int file_no)
{
	return (_putchar(ch, file_no));
}

/**
 * print_s - print str
 * @str: string to print
 * @file_no: Stream
 * Return: length of the variable or -1
 */
int print_s(char *str, int file_no)
{
	int j = 0;

	if (str == NULL)
		return (-1);
	while (str[j])
	{
		_putchar(str[j], file_no);
		j++;
	}
	return (j);
}

/**
 * print_d - print int
 * @i: num to print
 * @file_no: Stream
 * Return: length of the variable or -1
 */
int print_d(long i, int file_no)
{
	char *dtos;
	int j = 0;

	dtos = _dtos(i);
	while (dtos[j])
	{
		_putchar(dtos[j], file_no);
		j++;
	}
	free(dtos);
	return (j);
}
