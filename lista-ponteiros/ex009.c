/*
Implemente a função void swap(int *x, int *y), que deve trocar os valores de x e y entre
si, a partir do uso de ponteiros. Ou seja, x passará a ter o valor de y, e y terá o valor de x.
*/
#include <stdio.h>
#include <stdlib.h>

int swap(int *x, int *y);

int main() {
    int x, y, *px = &x, *py = &y;
    printf("Digite o valor de x: ");
    scanf("%d", &x);
    printf("Digite o valor de y: ");
    scanf("%d", &y);
    swap(&x, &y);
    printf("x: %d \n", x);
    printf("y: %d \n", y);
}

int swap(int *px, int *py) {
    int temp;
    temp = *px;
    *px = *py;
    *py = temp;
}