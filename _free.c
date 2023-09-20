#include "shell.h"
/**
 * _free - free pointers
 * @string: string
 * @sbuf: free this pointer
 */
void _free(char *string, struct stat *sbuf)
{
	free(string);
	free(sbuf);
}

/**
 * array_int - check array
 * @arr: the array
 * @str_size: string
 */
void array_int(char **arr, int str_size)
{
	int j;

	j = 0;
	while (j < str_size)
		arr[j++] = NULL;
}
