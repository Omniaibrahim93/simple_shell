#include "shell.h"

/**
 * main - Initialize the variables of the program.
 * @argc: Number of values received from the command line.
 * @argv: An array of strings containing values received from the command line.
 * Return: Zero on success.
 */
int main(int argc, char *argv[])
{
    shell_data data_struct = {NULL}, *data = &data_struct;

    init(argc, argv, data);

    show_prompt(data);

    return (0);
}

/**
 * init - Initialize the shell data.
 * @argc: Number of values received from the command line.
 * @argv: An array of strings containing values received from the command line.
 * @data: Shell data.
 */
void init(int argc, char *argv[], shell_data *data)
{
    data->program_name = argv[0];
    data->params = argc;
}
