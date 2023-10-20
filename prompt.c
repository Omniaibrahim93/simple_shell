#include "shell.h"
/**
 * show_prompt - prints $
 * @data: exe info struct.
 * Return: 0 for success
 */
int show_prompt(shell_data *data)
{
	char *command = NULL;
	size_t bufsize = 0;
	ssize_t bytes_read;

	while (1)
	{
		_print("$ ");

		bytes_read = getline(&command, &bufsize, stdin);

		if (bytes_read == EOF)
		{
			break;
		}

		execute(command, data);
	}

	if (command != NULL)
	{
		free(command);
	}

	return (0);
}
