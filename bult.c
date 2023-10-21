#include "main.h"

/**
 * built - a functi built-ins commands.
 * @args: user input .
 * @dynamic: dynamic ref.
 * @pname: program name.
 */
void built(char **args, ref_t *dynamic, char *pname)
{
	size_t a, b;

	builts_cmd cmds[] = {
		{"exit", _ext},
		{"cd", _cd},
		{"env", _env},
		{"setenv", _setenv},
		{"unsetenv", _unsetenv},
		{NULL, NULL}
	};

	for (a = 0; cmds[a].command_name; a++)
		for (b = 0; args[b]; b++)
			if (_strcmp(args[b], cmds[a].command_name) == 0)
				cmds[a].function(args, dynamic, pname);
}
