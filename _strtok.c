#include "shell.h"
/**
 * _strtok - tokenise argument
 * @arr: array
 * @str: arg to separate
 */
void _strtok(char **arr, char *str)
{
	int i = 0;

	str = strtok(str, " ");
	while (str != NULL)
	{
		arr[i++] = str;
		str = strtok(NULL, " ");
	}
}
