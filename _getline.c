#include "main.h"

/**
  * _getline - read line from file descriptor.
  * @lineptr: var to store i/p.
  * @nb: buf size.
  * @fdi: file descrip.
  * Return: the number of bytes readed or -1 (eof, err, ...).
  */

ssize_t _getline(char **lineptr, size_t *nb, int fdi)
{
	char buffer[BUFFER_SIZE];
	char *tmp = NULL;
	ssize_t total = 0;
	ssize_t nread;

	if (lineptr == NULL || nb == NULL)
		return (-1);
	if (*lineptr == NULL || *nb == 0)
	{
		*nb = BUFFER_SIZE;
		*lineptr = malloc((*nb) + 1);
		if (*lineptr == NULL)
			return (-1);
	}
	while (1)
	{
		nread = read(fdi, buffer, BUFFER_SIZE);
		if (nread == -1)
			return (-1);
		if (nread == 0)
			break;
		if ((size_t)(total + nread + 1) > *nb)
		{
			*nb = total + nread + 1;
			tmp = (char *)_realloc(*lineptr, (*nb) + 1);

			if (tmp == NULL)
				return (-1);

			*lineptr = tmp;
		}
		_memcpy(*lineptr + total, buffer, nread);
		total += nread;
		if (buffer[nread - 1] == '\n')
			break;
	}

	(*lineptr)[total] = '\0';
	return (total);
}
