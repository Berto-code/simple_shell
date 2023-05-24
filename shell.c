#include "shell.h"

#define MAX_COMMAND_LENGTH 100

void shell_prompt(void)
{
	printf("$ ");
	fflush(stdout);
}

void execute_command(char *command)
{
	pid_t pid = fork();

	if (pid == 0)
	{
	char *args[] = {command, NULL};

	execvp(command, args);
	fprintf(stderr, "Command '%s' not found.\n", command);
	exit(1);
	}
	else if (pid > 0)
	{
	wait(NULL);
	}
	else
	{
	fprintf(stderr, "Fork failed.\n");
	exit(1);
	}
}

int main(void)
{
	printf("Simple Shell\n");

	while (1)
	{
		shell_prompt();

	char command[MAX_COMMAND_LENGTH];

	if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL)
	{
		printf("\nExiting shell.\n");
		break;
	}

	size_t length = strlen(command);

	if (length > 0 && command[length - 1] == '\n')
	{
		command[length - 1] = '\0';
	}

	if (strlen(command) > 0)
	{
		execute_command(command);
	}
	}

	return (0);
}

