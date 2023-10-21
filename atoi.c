#include "main.h"

/**
  * isnum - check num
  * @n: character test
  * Return: 1 if number 0 otherwise
  */
int isnum(char n)
{
	if (n >= '0' && n <= '9')
		return (1);
	return (0);
}

/**
  * hyphens - check number of minus
  * @str: string  check
  * @is: where the iteration stopped
  * Return: number of hyphens
  */
int hyphens(char *str, int *is)
{
	char *str1 = str;
	int sum = 0;

	while (!isnum(*str1) && *str1 != '\0')
	{
		(*is)++;
		if (*str1++ == '-')
			sum++;
	}
	return (sum);
}

/**
  * _atoi - convert a string to integer
  * @str: str to convert
  * Return: integer that is converted
  */
int _atoi(char *str)
{
	int j = 0, nm, ml = 1;
	unsigned int ans = 0;
	char *a = str;

	nm = hyphens(a, &j);

	a += j;
	while (isnum(*++a) && *a != '\0')
		ml *= 10;

	str += j;
	while (isnum(*str) && *str != '\0')
	{
		ans += (*str++ - '0') * ml;
		ml /= 10;
	}
	if (nm % 2)
		return (-((unsigned int)ans));
	return (ans);
}
