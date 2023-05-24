#include "shell.h"

/**
 * analyze_patterns - Entry Point
 * @info: input
 * @arguments: input
**/

void analyze_patterns(general_t *info, char **arguments)
{
	int g;

	for (g = 0; arguments[i] != NULL; i++)
		arguments[g] = pattern_handler(info, arguments[g]);
}

/**
 * pattern_handler - Entry Point
 * @info: input
 * @string: input
 * Return: string
**/

char *pattern_handler(general_t *info, char *string)
{
	int g;

	for (g = 0; string[g] != '\0'; g++)
	{
		if (string[g] == '$' && string[g + 1] != '\0')
			string = replace_value(info, &g, string);
	}

	return (string);
}

/**
 * replace_value - Entry Point
 * @info: input
 * @index: input
 * @string: input
 * Return: string
**/

char *replace_value(general_t *info, int *index, char *string)
{
	int g, new_n, old_n;
	char *value;

	g = *index;
	g++;

	value = replacement(info, index, string + g);
	if (value == NULL)
	{
		string = _strcpy(string, "");

		return (string);
		;
	}

	old_n = _strlen(string);
	new_n = _strlen(value) + 1;

	string = _realloc(string, old_n, new_n);
	string = _strcpy(string, value);

	free_memory_p(value);
	*index = g;
	return (string);
}
