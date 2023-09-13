#include "m-shell.h"
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
		execlp(order, order, (char *)NULL);
		perror("execlp error");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}
