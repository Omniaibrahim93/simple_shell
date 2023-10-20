#include "main.h"

/**
  * inner_process - proces arguments.
  * @str: command to processed.
  * @path: path array.
  * @pname: prog name.
  * @command_num: cmd num.
  * @dynamic: dynam ref.
  */
void inner_process(char *str, char **path, char *pname,
		int command_num, ref_t *dynamic)
{
	int fond;
	char bufer[MAX_LENGTH];
	char **args;
	int j, space = 0;

	for (j = 0; str[j] == ' '; j++)
		space++;
	if (space == _stringlen(str))
		return;
	args = _tokenize(str, " \t\r\n\0");
	fond = check_cmd(args[0], path, bufer);
	switch (fond)
	{
		case 1:
			set_error_code(0);
			eval(bufer, args);
			if (args)
				free_buf(args);
			break;
		case 2:
			bult(args, dynamic, pname);
			if (args)
				free_buf(args);
			break;
		default:
			cmd_not_found(pname, command_num, args[0]);
			fflush(stderr);
			set_error_code(127);
			if (args)
				free_buf(args);
			break;
	}

}
/**
  * process - process the input.
  * @path: path environment variable.
  * @pname: shell name.
  * @isaty: is a tty ?
  */
void process(char **path, char *pname, int isaty)
{
	char *stri = NULL, **args_all, **args_semi;
	int j, semi_length;
	int command_num = 0;
	ref_t *dynamic = malloc(sizeof(ref_t));

	dynamic->ptr3 = path;
	stri = _readline(&command_num, isaty, dynamic);
	args_all = _tokenize(stri, "\n");
	args_semi = _tokenize(args_all[0], ";");
	dynamic->ptr1 = args_all;
	dynamic->ptr2 = args_semi;
	free(stri);
	for (semi_length = 0; args_semi[semi_length]; semi_length++)
		continue;
	if (semi_length > 1)
	{
		for (j = 0; args_semi[j]; j++)
			inner_process(args_semi[j], path, pname, command_num, dynamic);
		if (dynamic->ptr1)
			free_buf(dynamic->ptr1);
		if (dynamic->ptr2)
			free_buf(dynamic->ptr2);
		free(dynamic);
	}
	else
	{
		for (j = 0; args_all[j]; j++)
			inner_process(args_all[j], path, pname, command_num, dynamic);
		if (dynamic->ptr1)
			free_buf(dynamic->ptr1);
		if (dynamic->ptr2)
			free_buf(dynamic->ptr2);
		free(dynamic);
	}
}

/**
  * process_file - proc file content.
  * @path: path env var.
  * @pname: shell name.
  * @fname: file name.
  */
void process_file(char **path, char *pname, char *fname)
{
	char **args_all, *stri = NULL;
	int j;
	int command_num = 0;
	ref_t *dynamic_ref = malloc(sizeof(ref_t));

	stri = read_textfile(fname, MAX_LENGTH);
	if (stri == NULL)
	{
		file_not_found(pname, fname);
		exit(127);
	}
	args_all = _tokenize(stri, "\n");
	for (j = 0; args_all[j]; j++)
		inner_process(args_all[j], path, pname, command_num, dynamic_ref);
}
