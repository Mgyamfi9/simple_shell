#include "shell.h"
/**
 * _prog2 - check code
 * @ac: number of arguments
 * @av: arguments
 * @envp: environment
 */
void _prog2(int ac, char **av, char **envp)
{
	int l = 1;
	int str_i = 0;
	size_t no = 0;
	char *s = NULL;
	char *n_prog[3];
	struct stat *sbuf;

	sbuf = malloc(sizeof(struct stat));
	array_int(n_prog, 3);
	while (true)
	{
		l = getline(&s, &no, stdin);
		if (l == -1)
		{
			_free(s, sbuf);
			break;
		}
		*(s + (l - 1)) = '\0';
		_strtok(n_prog, s);
		if (n_prog[0] == NULL)
			continue;
		if (strcmp(n_prog[0], "ls") == 0)
			n_prog[0] = "/bin/ls";
		str_i = lstat(n_prog[0], sbuf);
		if (str_i == -1)
			error(ac, n_prog[0], av);
		else
			_execute(n_prog, envp);
	}
}
