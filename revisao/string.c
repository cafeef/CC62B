#include <stdio.h>
int main() {
    char nome[50];
    int i;
    scanf("%[^\n]", nome);
    for (i = 0; nome[i] != '\0'; i++)
        printf("%c", nome[i]);
}