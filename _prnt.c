#include "main.h"
/**
 * _prnt - a basic print function
 * @text: input to print
*/
void _prnt(char *text)
{
	write(STDOUT_FILENO, text, strlen(text));
}