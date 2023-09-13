#include "shell.h"
/**
 * main - entry point of shell program
 * Return: 0 always success
 */
int main(void)
{
	char input[1024];

	while (true)
	{
		_prompt();
		read_input(input, sizeof(input));
		_execute(input);
	}
	return (0);
}
