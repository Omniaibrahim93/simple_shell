#include "main.h"

/**
 * _tokenize - func split a string into tokens.
 * @str: the string to tokenize
 * @split: the delim used to split's string.
 * Return: the tokenize string on success, on failure NULL.
 */

char **_tokenize(char *str, char *split)
{
	char **toks;
	int delim = 0;
	int j, indx = 0;
	int strt, end;

	if (!str || !split)
		return (NULL);
	for (j = 0; str[j]; j++)
		if (_strchr(split, str[j]) != NULL)
			delim++;
	toks = (char **)malloc(sizeof(char *) * (delim + 2));
	if (!toks)
	{
		perror("malloc");
		return (NULL);
	}

	strt = 0;
	while (str[strt] != '\0')
	{
		while (str[strt] != '\0' && _strchr(split, str[strt]) != NULL)
			strt++;
		if (str[strt] == '\0')
			break;

		end = strt;
		while (str[end] != '\0' && _strchr(split, str[end]) == NULL)
			end++;

		toks[indx] = malloc(end - strt + 1);
		_strncpy(toks[indx], str + strt, end - strt);
		toks[indx][end - strt] = '\0';
		indx++;
		strt = end;
	}

	toks[indx] = NULL;

	return (toks);
}
