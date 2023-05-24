#include "shell.h"

/**
 * is_executable - Check if a filename has permissions
 * for running
 *
 * @filename: Filename to check
 *
 * Return: On success, PERMISSIONS
 * On error, NON_PERMISSIONS
 **/
int is_executable(char *filename)
{
	struct stat stats;

	if (stat(filename, &stats) == 0)
	{
		if (stats.st_mode & X_OK)
			return (PERMISSIONS);
		else
			return (NON_PERMISSIONS);
	}

	return (NON_FILE);
}

/**
 * is_file - Check if it's a file or binary
 * Description: Look for excute permissions and
 * if is a file
 *
 * @file: File to check
 *
 * Return: file with the correct permissions, PERMISSIONS
 * file but doesn't have permissions or doesn't exist, NON_PERMISSIONS
 * If it's not a file, NON_FILE
 **/
int is_file(char *file)
{
	int g, size;

	size = _strlen(file);
	for (g = 0; g < size; g++)
		if (file[g] == '/')
			return (is_executable(file));

	return (NON_FILE);
}
