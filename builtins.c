#include "shell.h"

/**
 * builtins - Check and execute the builtins
 *
 * @info: Information about the shell
 * @arguments: Commands and arguments
 *
 * Return: If the command passed is a builtins
 * return _TRUE if not return _FALSE
 **/
int builtins(general_t *info, char **arguments)
{
	int status;

	status = check_builtin(info, arguments);
	if (status == _FALSE)
		return (_FALSE);

	return (_TRUE);
}


/**
 * check_builtin - Check if the actual command is a builtin_t
 * or not
 *
 * @info: General information about the shell
 * @arguments: Arguments of the command
 *
 * Return: If the command is an actual builtin, return _TRUE
 * if not _FALSE
 **/
int check_builtin(general_t *info, char **arguments)
{
	int g, size;
	builtin_t builtins[] = {
		{"exit", bin_exit},
		{"env", bin_env}
	};

	size = sizeof(builtins) / sizeof(builtins[0]);
	for (g = 0; g < size; g++)
	{
		if (_strcmp(info->command, builtins[i].command) == 0)
		{
			builtins[g].func(info, arguments);
			return (_TRUE);
		}
	}

	return (_FALSE);
}
