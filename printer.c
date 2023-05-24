#include "shell.h"
/**
 * _putchar_to_fd - Prints a character to a specific file
 * descriptor
 *
 * @c: Character to print
 * @fd: Place character is printed
 *
 * Return: On success 1.
 * On error -1, and error is set appropriately.
 **/
int _putchar_to_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}


/**
 * print_to_fd - Prints a string
 *
 * @msg: String to print in the fd specified
 * @fd: File descriptor to print
 *
 * Return: On success numbers of bytes printed.
 * On error -1, and error is set appropriately.
 **/
int print_to_fd(char *msg, int fd)
{
	int size;

	size = _strlen(msg);

	return (write(fd, msg, size));
}
