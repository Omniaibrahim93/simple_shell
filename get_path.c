#include "main.h"

/**
  * getpath - Path environment.
  * Return: pointer to path value.
  */
char *getpath(void)
{
	return (_getenv("PATH"));
}
