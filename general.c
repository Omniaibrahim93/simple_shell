#include "main.h"

/**
  * _getenv - get the value of env.
  * @str: name of the env.
  * Return: string corrospond to value of the s.
  */
char *_getenv(char *str)
{
	unsigned int j = 0;
	char **env = environ;
	size_t length = _strlen(s);

	while (env[j] && _strncmp(env[j], str, length))
		j++;

	if (env[j] == NULL)
		return (NULL);
	return (env[j] + length + 1);
}

/**
  * set_err_code - set value of ERR_CODE.
  * @err: new error value.
  * Return: return the value of ERR_CODE.
  */
int set_err_code(int err)
{
	static int ERR_CODE;

	if (-99 == err)
		return (ERR_CODE);
	ERR_CODE = err;
	return (err);
}

/**
  * get_err_code - get value of ERR_CODE.
  * Return: ERR_CODE.
  */
int get_err_code(void)
{
	return (set_err_code(-99));
}

/**
  * set_cmd_num - set cmd num.
  * @numb: cmd num.
  * Return: cmd Num.
  */
int set_cmd_num(int numb)
{
	static int CMD_NUM;

	if (-99 == numb)
		return (CMD_NUM);
	CMD_NUM = numb;
	return (numb);
}

/**
  * get_cmd_num - get command number.
  * Return: command number.
  */
int get_cmd_num(void)
{
	return (set_cmd_num(-99));
}
