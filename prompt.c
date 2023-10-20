#include "shell.h"

/**
 * show_prompt - Prints the '$' prompt and reads user input.
 * @data: Pointer to the shell_data struct.
 * Return: 0 for success.
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
