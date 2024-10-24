#include <stdio.h>
int main() {
	int x= 5;
	int *p = &x;
	printf("%x\n", p);
	p++;
	printf("%x\n", p);
	p = p + 15;
	printf("%x\n", p);
	p = p - 2;
	printf("%x\n", p);
}