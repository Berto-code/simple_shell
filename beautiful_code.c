#include <stdio.h>

#define MAX_VALUE 100

typedef
{
	int x;
	int y;
} Point;

void print_point(Point p);

int main(void)
{
	Point p;

	p.x = 5;
	p.y = 10;

	print_point(p);

	return (0);
}

void print_point(Point p)
{
	printf("Point coordinates: (%d, %d)\n", p.x, p.y);
}

