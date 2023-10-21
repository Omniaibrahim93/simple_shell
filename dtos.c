#include "main.h"
#include <stdlib.h>

/**
 * _dtos - int to str.
 * @di: int to convert
 * Return: char pointer
 */
char *_dtos(long di)
{
	int length = 1;
	int sin = 0;
	int j = 0;
	int ent;
	long div = 10;
	char *buff;

	if (di < 0)
	{
		sin = 1;
		di = -di;
	}
	while (di / div > 0)
	{
		div *= 10;
		length++;
	}
	buff = malloc(sizeof(char) * length + sin + 1);
	if (sin)
		buff[j++] = '-';
	while (div > 1)
	{
		div /= 10;
		ent = di / div;
		buff[j++] = '0' + (ent % 10);
	}
	buff[j] = '\0';
	return (buff);
}
