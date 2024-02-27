#include "main.h"
/**
 * my shell program
*/
int main(void)
{
	char command[256];

	while (true)
	{
		_prompt();
		read_command(command,sizeof(command));
		execute_command(command);
	}
	
	return (0);
}