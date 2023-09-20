#include "shell.h"
/**
 * error - code errors to check
 * @ac: number of file
 * @string: the file to execute
 * @av: number of inputs
 */
void error(int ac, char *string, char **av)
{
	write(1, av[ac - 1], strlen(av[ac - 1]));
	write(2, ": 1:", 4);
	write(2, string, strlen(string));
	write(2, ": not found\n", 12);
}
