#include "main.h"
/**
 * execute_command - this function execute the command taken from the stdin
 * @command: input from stdin
*/
void execute_command(char* command)
{
	pid_t child_pid = fork();/*creates a process*/

	int i;
	char *args[256];
	char *path = "/bin/";
	int arg_count = 0;
	char *envp[] = {NULL};

	char *token = strtok((char *)command, " ");
	while (token != NULL && arg_count < 255)
	{
		args[arg_count++] = token;
		token = strtok(NULL, " ");
	}
	args[arg_count] = NULL;

	if (args[0] == NULL)
	{
		return;
	}

	if (strcmp(args[0], "exit") == 0)
	{
		int status = EXIT_SUCCESS;
		if (args[1] != NULL)
		{
			status = atoi(args[1]);
		}
		exit(status);
	}

	if (strcmp(args[0], "env") == 0)
	{
		for ( i = 0; environ[i] != NULL; i++)
		{
			printf("%s\n", environ[i]);
		}
		
	}
	
	if (strcmp(args[0], "clear") == 0)
	{
		system("clear");
		return;
	}
	
	

	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		char full_path[256];

		if (args[0][0] == '/')
		{
			strcpy(full_path, args[0]);
		}
		else
		{
			strcpy(full_path, path);
			strcat(full_path, args[0]);
		}
		execve(full_path, args, envp);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}