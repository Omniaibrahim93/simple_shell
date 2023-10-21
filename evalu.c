#include "main.h"

/**
  * eval - evaluat cmd.
  * @command: command to be executed.
  * @args: argument vect.
  */
void eval(char *command, char **args)
{
	pid_t chld_pid;

	chld_pid = fork();
	execute(chld_pid, command, args);
}
