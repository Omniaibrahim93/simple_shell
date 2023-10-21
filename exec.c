#include "main.h"

/**
  * execute - exec command.
  * @pid: proc id.
  * @command: the cmd to be exec.
  * @args: argument vector.
  */
void execute(pid_t pid, char *command, char **args)
{
	int statu;

	if (pid == 0)
	{
		if (execve(command, args, environ) == -1)
			perror("can't run command");
	}
	else
	{
		/* parent process wait for child process */
		waitpid(pid, &statu, 0);
		set_err_code(WEXITSTATUS(statu));
	}
}
