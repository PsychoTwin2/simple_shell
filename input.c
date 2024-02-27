#include "main.h"
/**
 * read_command - takes the input from the stdin
 * @command:variable to store the line from stdin
 * @size: varaible for the number of bytes the command has
*/
void read_command(char *command, size_t size)
{
	if (fgets(command, size, stdin) == NULL)
	{
		if (feof(stdin))
		{
			_prnt("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			_prnt("Error while reading input.\n");
			exit(EXIT_FAILURE);
		}
	}
	command[strcspn(command, "\n")] = '\0';
}