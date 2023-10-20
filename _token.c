#include "main.h"

/**
 * _tokenize - fun split string into tokens.
 * @str: the string to tokenize
 * @split: the delim used to split's string.
 * Return: the tokenize string on success, on failure NULL.
 */

char **_tokenize(char *str, char *split)
{
	char **tokss;
	int delm = 0;
	int j, indx = 0;
	int start, end;

	if (!str || !split)
		return (NULL);
	for (j = 0; str[j]; j++)
		if (_stringchr(split, str[j]) != NULL)
			delm++;
	tokss = (char **)malloc(sizeof(char *) * (delm + 2));
	if (!tokss)
	{
		perror("malloc");
		return (NULL);
	}

	start = 0;
	while (str[start] != '\0')
	{
		while (str[start] != '\0' && _stringchr(split, str[start]) != NULL)
			start++;
		if (str[start] == '\0')
			break;

		end = start;
		while (str[end] != '\0' && _stringchr(split, str[end]) == NULL)
			end++;

		tokss[indx] = malloc(end - start + 1);
		_stringncpy(tokss[indx], str + start, end - start);
		tokss[indx][end - start] = '\0';
		indx++;
		start = end;
	}

	tokss[indx] = NULL;

	return (tokss);
}
