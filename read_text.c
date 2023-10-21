#include "main.h"
#include <stdlib.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * read_textfile - reads text and prints it to the o/p.
 * @filename: file name.
 * @letters: number of letters to print.
 * Return: string in the file
 */
char *read_textfile(char *filename, size_t letters)
{
	int fdi, rdi;
	char *bufer;

	fdi = rdi = 0;
	if (!filename || !letters)
		return (NULL);
	fdi = open(filename, O_RDONLY);
	if (fdi < 0)
		return (NULL);

	bufer = malloc(sizeof(char) * letters + 1);
	if (!bufer)
		return (NULL);
	rdi = read(fdi, bufer, letters);
	if (rdi < 0)
	{
		free(bufer);
		return (NULL);
	}
	bufer[letters] = '\0';

	close(fdi);
	return (bufer);
}
