/*
 Implemente a função void calcMedia(int *array, int n, int *resultado); que calcula a
média dos valores de uma array, de tamanho n. Em vez de retornar o valor calculado, ele
deve ser atribuído diretamente em resultado.
*/

#include <stdio.h>

void calcMedia(int *array, int n, float *resultado);

int main() {
    int array[5] = {1, 2, 3, 4, 5}, n;
    float media, *resultado = &media;
    calcMedia(array, n, resultado);
    printf("O resultado é: %f", *resultado);
}

void calcMedia(int *array, int n, float *resultado) {
    int i;
    for (i = 0; i < 5; i++)
        n = n + *(array + i);
    *resultado = n/5;
}