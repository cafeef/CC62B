#include <stdio.h>
int main() {
	void *p;
	int *p1, p2 = 10;
	p = &p2;
	p1 = &p2;
	printf("Endereço em p: %p\n", p);
	p = &p1;
	printf("Endereço em p: %p\n", p);
	p = p1;
	printf("Endereço em p: %p\n", p);
}