#include <stdio.h>

void incluir(int vcod[], float vsaldo[], int tam);

int main() {
    int tam;
    printf("Quantos clientes tem em seu banco? ");
    scanf("%d", &tam);
    int vcod[tam];
    float vsaldo[tam];
    incluir(vcod, vsaldo, tam);
}

void incluir(int vcod[], float vsaldo[], int tam) {
    int i;
    for (i = 0; i < tam; i++) {
        vcod[i] = i + 1;
        printf("Digite o saldo do cliente %d: ", vcod[i]);
        scanf("%f", &vsaldo[i]);
    }
    for (i = 0; i < tam; i++) {
        printf("Saldo do cliente %d: %.2f\n", vcod[i], vsaldo[i]);
    }
}