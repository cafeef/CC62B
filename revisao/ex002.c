#include <stdio.h>
int main() {
    int numero, n1, n11, soma, i;
    do {
    printf("Informe numero (0 - 99999)");
    scanf("%d", &numero);   
    } while (numero < 0 || numero > 99999);
    for (i = 10000; i != 10; i/10) {
        n1 = numero / i;
        numero = numero%i;
        soma = n1 + soma;
    }
    printf("%d", soma);
    return 0;
}