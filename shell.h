#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 64
#define MAX_ALIASES 64

typedef
{
	char *name;
	char *value;
} Alias;

extern Alias aliases[MAX_ALIASES];
extern int num_aliases;

void replace_variable(char *command);
int parse_arguments(char *command, char *arguments[]);
int is_exit_builtin(const char *command);
void handle_exit(char *arguments[]);
int is_setenv_builtin(const char *command);
void handle_setenv(char *arguments[]);
int is_unsetenv_builtin(const char *command);
void handle_unsetenv(char *arguments[]);
int is_cd_builtin(const char *command);
void handle_cd(char *arguments[]);
int is_alias_builtin(const char *command);
void handle_alias(char *arguments[]);
void execute_command(const char *command, char *arguments[], char *envp[]);
void execute_commands(char *commands[], int num_commands, char *envp[]);

#endif /* SHELL_H */
