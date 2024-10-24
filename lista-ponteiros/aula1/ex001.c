#include <stdio.h>
int main() {
	int num1 = 15;
	int *p;
	p = &num1;
	printf("\nnum1: %d", num1);
	printf("\nnum1: %p", &num1);
	printf("\np: %p", p);
	printf("\n*p: %d", *p);
	*p = 12;
	printf("\n*p: %d", *p);
}