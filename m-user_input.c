#include "shell.h"
/**
 * read_input - read user input
 * @input: user input
 * @size: size of user input
 */
void read_input(char *input, size_t size)
{
	if (fgets(input, size, stdin) == NULL)
	{
		if (feof(stdin))
		{
			_write("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			_write("Error reading input.\n");
			exit(EXIT_FAILURE);
		}
	}
	input[strcspn(input, "\n")] = '\0';
}
