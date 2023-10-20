#include "main.h"

/**
  * eval - evaluate commands.
  * @command: command to execute.
  * @args: arg vector.
  */
void eval(char *command, char **args)
{
	pid_t child_pid;

	child_pid = fork();
	execute(child_pid, command, args);
}
