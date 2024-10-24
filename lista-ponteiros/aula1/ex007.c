#include <stdio.h>
int main() {
	int *p, *p1, x, y;
	p = &x;
	p1 = &y;
	if (p > p1)
		printf("p > p1");
	else
		printf("p < p1");
}