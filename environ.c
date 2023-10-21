#include "main.h"

/**
 * _env - env command
 * @arg: param
 * @dynamic: dynamic ref.
 * @pname: prog name.
 * Return: always 0 on success
 */

int _env(char **arg, ref_t *dynamic, char *pname)
{
	char *argVec[] = {"/bin/sh", "-c", "env", NULL};

	(void)pname;
	(void)arg;
	(void)dynamic;

	execve("/bin/sh", argVec, environ);
	return (0);
}
