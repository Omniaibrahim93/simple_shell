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
	char cwd[1024], *dira;
	int chan = 0;

	(void)pname;
	if (getcwd(cwd, 1024) == NULL)
	{
		perror("getcwd");
		return (-1);
	}

	dira = _path(arg);
	if (dira == NULL)
		return (-1);

	chan = chdir(dira);

	if (chan == -1)
	{
		perror("chdir");
		return (-1);
	}


	/* -> Update PWD, OLDPWD */
	if (_set("PWD", dira) == -1)
		return (-1);

	if (_set("OLDPWD", cwd) == -1)
		return (-1);

	set_error_code(0);
	return (0);

}

/**
 * _path - a help function checks the path input from user.
 * @arg: parameter for user input.
 * Return: the Path.
 */

char *_path(char **arg)
{

	if (arg[1] == NULL)
		return (_getenv("HOME"));
	else if (_stringcmp(arg[1], "-") == 0)
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
 * _set - a modified version of setenv, to handle hcanging PWD, OLDPWD
 * @name: name of the variable.
 * @value: the value that should contain in the name.
 * Return: 0 on success, -1 on failure
 */

int _set(char *name, char *value)
{
	char *ne;

	ne = malloc(_stringlen(name) + _stringlen(value) + 2);
	if (ne == NULL)
		return (-1);

	_stringcpy(ne, name);
	_stringcat(ne, "=");
	_stringcat(ne, value);

	if (putenv(ne) == -1)
		perror("putenv");
	free(ne);
	return (0);
}
