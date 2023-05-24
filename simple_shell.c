#include <SHELL_H>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * main - Entry point
 *
 * Description - Initialize variables and display the prompt and read
 * and execute commands on input.
 *
 * Return: Always 0 (Success)
 */

int main(void)
{

	char *command = NULL;
	size_t command_len = 0;
	int status;

	printf("$ ");

	while (getline(&command, &command_len, stdin) != -1)
	{
	command[strcspn(command, "\n")] = '\0';
	if (command[0] == '\0')
	{
	continue;
	}

	pid_t pid = fork();

	if (pid == 0)
	{
	execve(command, NULL, environ);
	perror("execve");
	exit(EXIT_FAILURE);
	}

	wait(&status);

	if (!WIFEXITED(status) || WEXITSTATUS(status))
	{
	printf("Error: %d\n", WEXITSTATUS(status));
	}

	printf("$ ");
	}
	return (0);
}
