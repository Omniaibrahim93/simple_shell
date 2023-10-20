#include "main.h"

/**
 * print_c - print char.
 * @c: char to be printed
 * @file_no: Stream
 * Return: length of the variable or -1
 */
int print_c(char c, int file_no)
{
	return (_putchar(c, file_no));
}

/**
 * print_s - print a string
 * @str: string to be printed
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
 * print_d - print an integer
 * @di: number to be printed
 * @file_no: Stream
 * Return: length of the variable or -1
 */
int print_d(long di, int file_no)
{
	char *dtos;
	int j = 0;

	dtos = _dtos(di);
	while (dtos[j])
	{
		_putchar(dtos[j], file_no);
		j++;
	}
	free(dtos);
	return (j);
}
