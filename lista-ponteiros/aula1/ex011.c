#include <stdio.h>
void soma_mais_um(int *x);

int main() {
	int x = 10;
	int *p = &x;
	int **p2 = &p;
	printf("p2: %d\n", p2);
	printf("p2: %d\n", *p2);
	printf("p2: %d\n", **p2);
}