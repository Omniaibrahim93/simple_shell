#include "main.h"
#include <stdlib.h>

/**
 * _dtos - integer to string.
 * @di: integer to convert
 * Return: char pointer
 */
char *_dtos(long di)
{
	int length = 1;
	int sin = 0;
	int i = 0;
	int ent;
	long divi = 10;
	char *bufer;

	if (di < 0)
	{
		sin = 1;
		di = -di;
	}
	while (di / divi > 0)
	{
		divi *= 10;
		length++;
	}
	bufer = malloc(sizeof(char) * length + sin + 1);
	if (sin)
		bufer[i++] = '-';
	while (divi > 1)
	{
		divi /= 10;
		ent = di / divi;
		bufer[i++] = '0' + (ent % 10);
	}
	bufer[i] = '\0';
	return (bufer);
}
