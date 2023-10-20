#include "main.h"

/**
  * isnumb - check for numbers
  * @b: character to test
  * Return: 1 if number 0 otherwise
  */
int isnumb(char b)
{
	if (b >= '0' && b <= '9')
		return (1);
	return (0);
}

/**
  * hypen - check number of minus signs
  * @str: string to check
  * @i: where the iteration stopped
  * Return: number of hyphens
  */
int hypen(char *str, int *i)
{
	char *str1 = str;
	int summ = 0;

	while (!isnumb(*str1) && *str1 != '\0')
	{
		(*i)++;
		if (*str1++ == '-')
			summ++;
	}
	return (summ);
}

/**
  * _atoi - convert a string to integer
  * @str: string to convert
  * Return: integer that is converted
  */
int _atoi(char *str)
{
	int j = 0, num, ml = 1;
	unsigned int answ = 0;
	char *a = str;

	num = hypen(a, &j);

	a += j;
	while (isnumb(*++a) && *a != '\0')
		ml *= 10;

	str += j;
	while (isnumb(*str) && *str != '\0')
	{
		answ += (*str++ - '0') * ml;
		ml /= 10;
	}
	if (num % 2)
		return (-((unsigned int)answ));
	return (answ);
}
