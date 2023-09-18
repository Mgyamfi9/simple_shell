#include "shell.h"
/**
 * _execute - function to execute
 * @order: command to execute
 * @envp: environment variable
 */
void _execute(const char *order, char *envp[])
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
		/*char *directory = "/bin";*/
		int arg_number = 0;
		char *token = strtok((char *)order, " ");
		char *exec_name;
		char full_path[256];
		char *path;
		char *path_token;

		while (token != NULL)
		{
			arguments[arg_number++] = token;
			token = strtok(NULL, " ");
		}
		arguments[arg_number] = NULL;

		exec_name = strrchr(arguments[0],'/');
		if (exec_name == NULL)
		{
			exec_name = arguments[0];
		}
		else
		{
			exec_name++;
		}
		path = getenv("PATH");
		if (path == NULL)
		{
			fprintf(stderr, "Error: PATH env is not set.\n");
			exit(EXIT_FAILURE);
		}
		path_token = strtok(path, ":");
		while (path_token != NULL)
		{
			snprintf(full_path, sizeof(full_path), "%s/%s", path_token, exec_name);
			if (access(full_path, X_OK) == 0)
			{
				break;
			}
			path_token = strtok(NULL, ":");
		}
	       	if (path_token == NULL)
		{
			fprintf(stderr, "Error: %s not found in PATH.\n", exec_name);
			exit(EXIT_FAILURE);
		}
		if (execve(full_path, arguments, envp) == -1)
		{
			perror("execve");
			fprintf(stderr, "Error executing command. Path: %s\n", exec_name);
			exit(EXIT_FAILURE);
		}
		fprintf(stderr, "Error executing command.\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}
