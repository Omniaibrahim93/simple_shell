#include "main.h"

/**
  * execute - execute a command.
  * @pid: process id.
  * @command: the command to be executed.
  * @args: argument vector.
  */
void execute(pid_t pid, char *command, char **args)
{
	int stattus;

	if (pid == 0)
	{
		if (execve(command, args, environ) == -1)
			perror("can't run command");
	}
	else
	{
		waitpid(pid, &stattus, 0);
		set_error_code(WEXITSTATUS(stattus));
	}
}
