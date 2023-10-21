#include "main.h"

/**
  * getpath - Path env var value.
  * Return: char ptr to path value.
  */
char *getpath(void)
{
	return (_getenv("PATH"));
}
