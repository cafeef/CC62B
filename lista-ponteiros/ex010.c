/*
Escreva uma função que receba como parâmetro um vetor e um valor a ser buscado.
Caso encontre algum elemento no vetor com o mesmo valor, retorne o endereço de memória
desse elemento. Caso contrário, retorne NULL.
*/

#include <stdio.h>

int* buscaValor(int *vetor, int valor);

int main() {
    int vetor[5] = {1, 2, 3, 4, 5}, valor, *retorno;
    printf("Digite o valor que deseja buscar: ");
    scanf("%d", &valor);
    retorno = buscaValor(vetor, valor);
    if (retorno == NULL)
        printf("Número não encontrado");
    else
        printf("Endereço de %d: %d", valor, (void*)retorno);
}

int* buscaValor(int *vetor, int valor) {
    int i;
    for (i = 0; i < 5; i++) {
        if (*vetor == valor)
            return vetor;
    }
    return NULL;
}