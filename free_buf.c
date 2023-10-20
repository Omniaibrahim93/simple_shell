#include "main.h"

/**
  * free_buf - free buffer.
  * @arg: buf to free.
  */
void free_buf(char **arg)
{
	int j;

	for (j = 0; arg[j]; j++)
		free(arg[j]);
	free(arg);
}
