#include "main.h"

char *_path(char **arg);
int _set(char *name, char *value);

/**
 * _cd - our own cd command
 * @arg: parameter
 * @dynamic: struct
 * @pname: program name.
 * Return: Always 0 on success, -1 on failure.
 */

int _cd(char **arg, __attribute__((unused))ref_t *dynamic, char *pname)
{
	char cwd[1024], *diri;
	int cha = 0;

	(void)pname;
	if (getcwd(cwd, 1024) == NULL)
	{
		perror("getcwd");
		return (-1);
	}

	diri = _path(arg);
	if (diri == NULL)
		return (-1);

	cha = chdir(diri);

	if (cha == -1)
	{
		perror("chdir");
		return (-1);
	}


	/* -> Update PWD, OLDPWD */
	if (_set("PWD", diri) == -1)
		return (-1);

	if (_set("OLDPWD", cwd) == -1)
		return (-1);

	set_err_code(0);
	return (0);

}

/**
 * _path - a help function.
 * @arg: param for user input.
 * Return: the Path.
 */

char *_path(char **arg)
{

	if (arg[1] == NULL)
		return (_getenv("HOME"));
	else if (_strcmp(arg[1], "-") == 0)
	{

		if (_getenv("OLDPWD") == NULL)
			return (NULL);
		else
			return (_getenv("OLDPWD"));
	}
	else
		return (arg[1]);
}


/**
 * _set - a modified version of seten.
 * @name: name of the var.
 * @value: the value that should contain in the name.
 * Return: 0 on success, -1 on failure
 */

int _set(char *name, char *value)
{
	char *newe;

	newe = malloc(_strlen(name) + _strlen(value) + 2);
	if (newe == NULL)
		return (-1);

	_strcpy(newe, name);
	_strcat(newe, "=");
	_strcat(newe, value);

	if (putenv(newe) == -1)
		perror("putenv");
	free(newe);
	return (0);
}
