/* 13. Faça uma função que, dada uma string de entrada, deixe todas suas letras em maiúsculo.*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void RetornaMaiusculo(char *string);

int main() {
    int i;
    char string[20], *p = string;
    printf("Digite a string desejada: ");
    scanf("%s", string);
    RetornaMaiusculo(string);
    printf("A string em maiúsculo é: ");
    for (i = 0; i < strlen(string); i++)
        printf("%c", *(string + i));
}

void RetornaMaiusculo(char *string) {
    int i;
    for (i = 0; i < strlen(string); i++)
        *(string + i) = toupper(*(string + i));
    
}