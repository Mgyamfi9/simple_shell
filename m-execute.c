#include "shell.h"
/**
 * _execute - function to execute
 * @order: command to execute
 */
void _execute(const char *order)
{
	pid_t _childpid = fork();

	if (_childpid == -1)
	{
		perror("fork error");
		exit(EXIT_FAILURE);
	}
	else if (_childpid == 0)
	{
		char *arguments[1024];
		int arg_number = 0;

		char *token = strtok((char *)order, " ");

		while (token != NULL)
		{
			arguments[arg_number++] = token;
			token = strtok(NULL, " ");
		}
		arguments[arg_number] = NULL;
		execvp(arguments[0], arguments);
		_write("Error executing command.\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}
