#include "shell.h"
/**
 * _prog1 - initiate program
 * @ac: number of arguments
 * @av: arguments
 * @envp: environment
 */
void _prog1(int ac, char **av, char **envp)
{
	int l = 1;
	int str_i = 0;
	char *s = NULL;
	char *n_prog[3];
	struct stat *sbuf;
	size_t no = 0;

	sbuf = malloc(sizeof(struct stat));
	array_int(n_prog, 3);
	while (true)
	{
		write(1, "m_shell~ ", 9);
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
		str_i = lstat(s, sbuf);
		if (str_i == -1)
		{
			error(ac, n_prog[0], av);
		}
		else
			_execute(n_prog, envp);
	}
}
