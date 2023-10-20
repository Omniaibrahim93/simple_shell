#include "main.h"

/**
 * bult - a function that handles the built-ins commands.
 * @args: user input tokenized as arguments.
 * @dynamic: dynamic reference.
 * @pname: program name.
 */
void bult(char **args, ref_t *dynamic, char *pname)
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
			if (_stringcmp(args[b], cmds[a].command_name) == 0)
				cmds[a].function(args, dynamic, pname);
}
