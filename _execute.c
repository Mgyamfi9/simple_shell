#include "shell.h"
/**
 * _execute - execute code
 * @arguments: arguments
 * @env: environment
 */
void _execute(char **arguments, char **env)
{
	int _childid;
	int _wait;

	_childid = fork();
	if (_childid == 0)
		execve(arguments[0], arguments, env);
	else
		wait(&_wait);
}
