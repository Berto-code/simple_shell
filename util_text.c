#include "shell.h"

/**
 * _strlen - Return the length of a string
 *
 * @msg: String to calculate length
 *
 * Return: Length of the string
 **/
int _strlen(char *msg)
{
	int g;

	for (g = 0; msg[g] != '\0'; g++)
		;

	return (g);
}

/**
 * _strcat - Concatenates two strings
 *
 * @dest: String concatenate
 * @src: Source string
 *
 * Return: A string concatenate
 */
char *_strcat(char *dest, char *src)
{
	int l_dest, g;

	l_dest = _strlen(dest);

	for (g = 0; src[g] != '\0'; g++, l_dest++)
		dest[l_dest] = src[g];

	dest[l_dest] = '\0';

	return (dest);
}

/**
 * _strcpy - Copy a string to another
 *
 * @dest: Destination copy
 * @src: Source for copy
 *
 * Return: Return the value of dest
 */
char *_strcpy(char *dest, char *src)
{
	int g;

	for (g = 0; src[g] != '\0'; g++)
		dest[g] = src[g];

	dest[g] = '\0';

	return (dest);
}


/**
 * _strdup - Pointer to a newly allocated space in memory
 *
 * @str: String to copy
 *
 * Return: String copied
 **/
char *_strdup(char *str)
{
	int size, g;
	char *dest;

	if (str == NULL)
		return (NULL);

	size = _strlen(str) + 1;
	dest = malloc(size * sizeof(char));
	if (dest == NULL)
		return (NULL);

	for (g = 0; g < size; g++)
		*(dest + g) = *(str + g);

	/* (dest + g) = 0; */

	return (dest);
}

/**
 * _strcmp - Compare two strings
 *
 * @s1: String 1
 * @s2: String 2
 *
 * Return: Integer
 */
int _strcmp(char *s1, char *s2)
{
	int g;

	for (g = 0; s1[g] != '\0'; g++)
	{
		if (s1[g] != s2[g])
			return (s1[g] - s2[g]);
	}

	return (0);
}
