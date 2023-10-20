#include "main.h"

/**
 * _stringncmp - funciton that compare two strings.
 * @str1: the 1st string.
 * @str2: the 2nd string.
 * @bn: buffer length to compare.
 * Return: (< 0) if first character doesn't match has a lower value in s1
 * than in s2.
 * ** (0) if both strings are equal.
 * ** (> 0) if first character doesn't match has greater value in s1
 * than in s2.
 */

int _stringncmp(char *str1, char *str2, size_t bn)
{
	if (!str1 || !str2)
		return (-1);

	while (bn && *str1 && (*str1 == *str2))
	{
		++str1;
		++str2;
		--bn;
	}
	if (bn == 0)
		return (0);
	else
		return (*(unsigned char *)str1 - *(unsigned char *)str2);
}
