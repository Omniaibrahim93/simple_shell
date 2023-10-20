#include "main.h"

/**
  * eval - evaluate commands.
  * @command: command to execute.
  * @args: arg vector.
  */
void eval(char *command, char **args)
{
	pid_t chld_pid;

	chld_pid = fork();
	execute(chld_pid, command, args);
}
