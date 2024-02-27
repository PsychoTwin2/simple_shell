#include "main.h"
/**
 * main - entry point of the shell program
 *
 * Descriptoion: this function loops and execute any command from the stdin
 * Return: 0;
*/
int main(void)
{
	char command[256];

	while (true)
	{
		_prompt();
		read_command(command, sizeof(command));
		execute_command(command);
	}
	return (0);
}
