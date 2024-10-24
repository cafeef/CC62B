#include <stdio.h>
int main() {
	int *p, *p1, x = 10;
	float y = 20.0;
	p = &x;
	printf("*p: %d \n", *p);
	p1 = p;
	printf("*p1: %d", *p1);
	p = &y;
}