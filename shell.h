#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define __silent __attribute__((__unused__))

/***** STRUCTURES *****/

/**
 * struct info- struct for the shell data
 * @program_name: the name of the executable
 * @params: number of args passed.
 */
typedef struct info
{
	char *program_name;
	int params;
} shell_data;

void init(int argc, char *argv[], shell_data *data);

/* Output functions */
int _print(char *string);
int _printe(char *string);
int show_prompt(shell_data *data);

int execute(char *command, shell_data *data);

/* String functions */
int _strlen(char *string);

#endif /* SHELL_H */
