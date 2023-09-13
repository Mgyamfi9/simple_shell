#include "shell.h"
/**
 * _write - prints text to the stdoutput
 * @text: text to print
 */
void _write(const char *text)
{
	write(STDOUT_FILENO, text, strlen(text));
}
