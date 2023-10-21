#include "main.h"

/**
  * _strcmp - compares 2 strs.
  * @s1: str 1
  * @s2: str 2
  * Return: 0 if equalls an integer otherwise
  */
int _strcmp(char *s1, char *s2)
{
	int length_s1 = 0, length_s2 = 0;
	int j = 0, nb;
	char *a = s1;
	char *b = s2;

	while (*a++ != '\0')
		length_s1++;
	while (*b++ != '\0')
		length_s2++;

	nb = (length_s1 > length_s2) ? length_s1 : length_s2;

	while (s1[j] == s2[j] && j < nb)
		j++;

	return (s1[j] - s2[j]);
}
