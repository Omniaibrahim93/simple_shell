#include "main.h"

/**
 * _unsetenv - delete env variables
 * @arg: user arguments
 * @dynamic: dynamic ref.
 * @pname: prog name.
 * Return: 0 on success, -1 on failure.
 */

int _unsetenv(char **arg, ref_t *dynamic, char *pname)
{
	int posi;
	char *var;

	(void)dynamic;
	(void)pname;

	for (posi = 0; arg[posi] != NULL; posi++)
		if (_strcmp(arg[posi], "unsetenv") == 0)
			break;

	var = getenv(arg[posi + 1]);
	if (var)
		*var = '\0';
	else
		return (-1);

	return (0);
}
