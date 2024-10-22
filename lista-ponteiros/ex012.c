/*
12. Implemente uma função que receba uma string e retorne o seu tamanho.
*/

#include <stdio.h>
#include <stdlib.h>

void RetornaTamanho(int *tam, char *string);

int main() {
    char string[20];
    int tam;
    printf("Digite a string: ");
    scanf("%s", string);
    RetornaTamanho(&tam, string);
    printf("O tamanho da string é: %d\n", tam);
}

void RetornaTamanho(int *tam, char *string) {
    int i;
    for (i = 0; *(string + i) != '\0' ; i++)
        *tam += 1;
}