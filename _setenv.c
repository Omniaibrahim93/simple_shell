#include "main.h"

/**
 * _setenv - our setenv;
 * @arg: user input
 * @dynamic: struct
 * @pname: prog name.
 * Return: 0 on success.
 */

int _setenv(char **arg, ref_t *dynamic, char *pname)
{
	int posi;
	char *newe;
	(void)dynamic;
	(void)pname;

	for (posi = 0; arg[posi] != NULL; posi++)
		if (_strcmp(arg[posi], "setenv") == 0)
			break;

	if (arg[posi + 1] == NULL || arg[posi + 2] == NULL)
		return (-1);

	newe = malloc(_strlen(arg[posi + 1]) * _strlen(arg[posi + 2]) + 3);

	if (newe == NULL)
	{
		perror("malloc");
		return (-1);
	}

	_strcpy(newe, arg[posi + 1]);
	_strcat(newe, "=");
	_strcat(newe, arg[posi + 2]);

	if (putenv(newe) == -1)
		return (-1);
	return (0);
}
