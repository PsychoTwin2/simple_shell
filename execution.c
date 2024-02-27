#include "main.h"
/**
 * execute_command - this function execute the command taken from the stdin
 * @command: input from stdin
*/
void execute_command(char *command)
{
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		process(command);
	}
	else
	{
		wait(NULL);
	}
}
/**
 * process - handles the execution of the child process
 * @command: input to use
*/
void process(char *command)
{
	char *args[256];
	int arg_count = 0;
	int i;
	char *envp[] = {NULL};
	char full_path[256];
	char *path = "/bin/";
	char *token = strtok((char *)command, " ");

	while (token != NULL && arg_count < 255)
	{
		args[arg_count++] = token;
		token = strtok(NULL, " ");
	}
	args[arg_count] = NULL;
	if (args[0] == NULL)
		return;
	else if (strcmp(args[0], "env") == 0)
	{
		for (i = 0; environ[i] != NULL; i++)
		{
			printf("%s\n", environ[i]);
		}
	}
	else if (strcmp(args[0], "clear") == 0)
	{
		system("clear");
		return;
	}
	else if (strcmp(args[0], "exit") == 0)
		exit(EXIT_SUCCESS);
	if (args[0][0] == '/')
		strcpy(full_path, args[0]);
	else
	{
		strcpy(full_path, path);
		strcat(full_path, args[0]);
	}
	execve(full_path, args, envp);
	perror("execve");
	exit(EXIT_FAILURE);
}
