#include "main.h"

/**
  * _getline - read line from the file descriptor.
  * @lineptr: variable to store input.
  * @bs: buffer size.
  * @fde: file descriptor.
  * Return: the number of bytes readed or -1 (eof, err, ...).
  */

ssize_t _getline(char **lineptr, size_t *bs, int fde)
{
	char buffer[BUFFER_SIZE];
	char *tmp = NULL;
	ssize_t tot = 0;
	ssize_t nread;

	if (lineptr == NULL || bs == NULL)
		return (-1);
	if (*lineptr == NULL || *bs == 0)
	{
		*bs = BUFFER_SIZE;
		*lineptr = malloc((*bs) + 1);
		if (*lineptr == NULL)
			return (-1);
	}
	while (1)
	{
		nread = read(fde, buffer, BUFFER_SIZE);
		if (nread == -1)
			return (-1);
		if (nread == 0)
			break;
		if ((size_t)(tot + nread + 1) > *bs)
		{
			*bs = tot + nread + 1;
			tmp = (char *)_realloc(*lineptr, (*bs) + 1);

			if (tmp == NULL)
				return (-1);

			*lineptr = tmp;
		}
		_memcpy(*lineptr + tot, buffer, nread);
		tot += nread;
		if (buffer[nread - 1] == '\n')
			break;
	}

	(*lineptr)[tot] = '\0';
	return (tot);
}
