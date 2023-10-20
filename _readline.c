#include "main.h"

/**
  * _readline - read a line from standared input
  * @command_num: input numbers.
  * @isaty: is a tty ?
  * @dynamic: dynamic reference.
  * Return: input string.
  */
char *_readline(int *command_num, int isaty, ref_t *dynamic)
{
	char *stri = NULL;
	size_t sizze = BUFFER_SIZE;
	ssize_t p = 1;

	while (p == 1 || (stri && stri[0] == '#'))
	{
		if (isaty)
		{
			write(STDOUT_FILENO, "$ ", 3);
			fflush(stdout);
		}
		p = _getline(&stri, &sizze, STDIN_FILENO);
		(*command_num)++;
		set_cmd_num(*command_num);
	}
	if (p == -1)
	{
		free(stri);
		free_buf(dynamic->ptr3);
		free(dynamic);
		exit(get_err_code());
	}
	else if (p == 0) /* CTRL+D Handler */
	{
		free(stri);
		write(STDOUT_FILENO, "\n", 2);
		fflush(stdout);
		free_buf(dynamic->ptr3);
		free(dynamic);
		exit(get_err_code());
	}
	return (stri);
}
