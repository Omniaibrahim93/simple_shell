#include "main.h"

/**
  * _stringcmp - compares two strings.
  * @str1: string 1
  * @str2: string 2
  * Return: 0 if equalls an integer otherwise
  */
int _stringcmp(char *str1, char *str2)
{
	int length_s1 = 0, length_s2 = 0;
	int j = 0, m;
	char *a = str1;
	char *b = str2;

	while (*a++ != '\0')
		length_s1++;
	while (*b++ != '\0')
		length_s2++;

	m = (length_s1 > length_s2) ? length_s1 : length_s2;

	while (str1[j] == str2[j] && j < m)
		j++;

	return (str1[j] - str2[j]);
}
