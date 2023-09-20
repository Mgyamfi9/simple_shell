#include "shell.h"
/**
 * main - entry point
 * @ac: number of arguments
 * @av: arguments
 * @env: environment
 * Return: 0 always success
 */
int main(int ac, char **av, char **env)
{
	if (!isatty(0))
	{
		_prog2(ac, av, env);
		return (0);
	}
	_prog1(ac, av, env);
	return (0);
}
