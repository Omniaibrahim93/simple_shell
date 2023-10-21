#include "main.h"

/**
  * free_buf - free a buf arr.
  * @arg: buf to free.
  */
void free_buf(char **arg)
{
	int j;

	for (j = 0; arg[j]; j++)
		free(arg[j]);
	free(arg);
}
