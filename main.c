#include "shell.h"

/**
 * main - initialize the variables of the program.
 * @argc: number of values received from the command line.
 * @argv: An array of strings contains values received from the command line.
 * Return: zero on succes.
 */
int main(int argc, char *argv[])
{
	shell_data data_struct = {NULL}, *data = &data_struct;

	init(argc, argv, data);

	show_prompt(data);

	return (0);
}

/**
 * init - init the shell data.
 * @argc: number of values received from the command line.
 * @argv: An array of strings contains values received from the command line.
 * @data: shell data.
 */
void init(int argc, char *argv[], shell_data *data)
{
	data->program_name = argv[0];
	data->params = argc;
}
