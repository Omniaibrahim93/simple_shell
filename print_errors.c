#include "main.h"

/**
  * cmd_not_found - print command not fond.
  * @pname: prog name.
  * @command_num: cmd execution num.
  * @command: cmd to be executed.
  */
void cmd_not_found(char *pname, int command_num, char *command)
{
	print_s(pname, STDERR_FILENO);
	print_c(':', STDERR_FILENO);
	print_c(' ', STDERR_FILENO);
	print_d(command_num, STDERR_FILENO);
	print_c(':', STDERR_FILENO);
	print_c(' ', STDERR_FILENO);
	print_s(command, STDERR_FILENO);
	print_c(':', STDERR_FILENO);
	print_c(' ', STDERR_FILENO);
	print_s("not found\n", STDERR_FILENO);
}

/**
  * print_illegal_number - print ilegal num error.
  * @args: argument.
  * @pname: prog name.
  */
void print_illegal_number(char **args, char *pname)
{
	print_s(pname, STDERR_FILENO);
	print_c(':', STDERR_FILENO);
	print_c(' ', STDERR_FILENO);
	print_d(get_cmd_num(), STDERR_FILENO);
	print_c(':', STDERR_FILENO);
	print_c(' ', STDERR_FILENO);
	print_s(args[0], STDERR_FILENO);
	print_c(':', STDERR_FILENO);
	print_c(' ', STDERR_FILENO);
	print_s("Illegal number", STDERR_FILENO);
	print_c(':', STDERR_FILENO);
	print_c(' ', STDERR_FILENO);
	print_s(args[1], STDERR_FILENO);
	print_c('\n', STDERR_FILENO);
}

/**
  * file_not_found - print file not found.
  * @pname: prog name.
  * @fname: file name.
  */
void file_not_found(char *pname, char *fname)
{
	print_s(pname, STDERR_FILENO);
	print_c(':', STDERR_FILENO);
	print_c(' ', STDERR_FILENO);
	print_s("0: ", STDERR_FILENO);
	print_s("Can't open ", STDERR_FILENO);
	print_s(fname, STDERR_FILENO);
	print_c('\n', STDERR_FILENO);
}
