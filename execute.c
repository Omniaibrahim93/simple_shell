#include "shell.h"
/**
 * execute - executes the command on child process
 * @command: command passed
 * @data: exe info struct.
 * Return: 0 for success
 */
int execute(char *command, shell_data *data)
{
	pid_t child_pid = fork();

	char *args[3];

	args[0] = command;
	args[1] = "/tmp";
	args[2] = NULL;

	if (child_pid == -1)
	{
		perror("Error forking process");
		exit(1);
	}
	else if (child_pid == 0)
	{
		size_t command_length = _strlen(command);

		if (command_length > 0 && command[command_length - 1] == '\n')
		{
			command[command_length - 1] = '\0';
		}

		execve(args[0], args, NULL);

		perror(data->program_name);
		exit(1);
	}
	else
	{
		int status;

		waitpid(child_pid, &status, 0);
	}
	return (0);
}
