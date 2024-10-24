#include <stdio.h>
int main() {
	void *p;
	int p2 = 10;
	p = &p2;
	printf("Endereço em p: %p\n", p);
	printf("Conteúdo de p: %d\n", *(int*)p);
}