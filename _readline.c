#include "main.h"

/**
  * _readline - read line from input
  * @command_num: i/p nums.
  * @isaty: is a tty ?
  * @dynamic: dynam ref.
  * Return: input string.
  */
char *_readline(int *command_num, int isaty, ref_t *dynamic)
{
	char *str1 = NULL;
	size_t sze = BUFFER_SIZE;
	ssize_t a = 1;

	while (a == 1 || (str1 && str1[0] == '#'))
	{
		if (isaty)
		{
			write(STDOUT_FILENO, "$ ", 3);
			fflush(stdout);
		}
		a = _getline(&str1, &sze, STDIN_FILENO);
		(*command_num)++;
		set_cmd_num(*command_num);
	}
	if (a == -1)
	{
		free(str1);
		free_buf(dynamic->ptr3);
		free(dynamic);
		exit(get_err_code());
	}
	else if (a == 0) /* CTRL+D Handler */
	{
		free(str1);
		write(STDOUT_FILENO, "\n", 2);
		fflush(stdout);
		free_buf(dynamic->ptr3);
		free(dynamic);
		exit(get_err_code());
	}
	return (str1);
}
