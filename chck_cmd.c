#include "main.h"

/**
  * check_cmd - check command exsistance.
  * @command: command  search.
  * @path: a list of strings.
  * @buf: the buffer to save the path of file commands
  * Return:	0 if not found
  *		1 if file command
  *		2 if built-in command.
  */
int check_cmd(char *command, char **path, char *buf)
{
	int j;
	char *builtins[] = {"env", "exit", "setenv", "unsetenv",
		"cd", "alias", NULL};

	if (!command)
		return (-1);
	if (access(command, F_OK) == 0)
	{
		_memset(buf, '\0', MAX_LENGTH);
		_strcpy(buf, command);
		return (1);
	}

	j = 0;
	while (builtins[j])
	{
		if (_strcmp(builtins[j++], command) == 0)
		{
			_memset(buf, '\0', MAX_LENGTH);
			_strcpy(buf, command);
			return (2);
		}
	}

	if (path == NULL)
		return (-1);
	j = 0;
	while (path[j])
	{
		_memset(buf, '\0', MAX_LENGTH);
		_strcpy(buf, path[j]);
		_strcat(buf, "/");
		_strcat(buf, command);
		if (access(buf, F_OK) == 0)
			return (1);
		j++;
	}
	return (0);
}
