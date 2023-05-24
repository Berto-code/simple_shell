#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: prints hello and your number
 *
 */

void main(void)
{
	int number;
	char name[256];

	printf("What is your name? ");
	fgets(name, 256, stdin);
	printf("What is your number? ");
	scanf("%d", &number);


	printf("Hello, %s! Your number is %d.\n", name, number);
}

