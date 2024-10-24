#include <stdio.h>
void soma_mais_um(int *x);

int main() {
	int x = 5;
	printf("Antes da função: %d\n", x);
	soma_mais_um(&x);
	printf("Depois da função: %d\n", x);
}

void soma_mais_um(int *x) {
	*x = *x + 1;
}