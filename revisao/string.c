#include <stdio.h>
int main() {
    char nome[50];
    int i;
    setbuf(stdin, NULL);
    scanf("%[^\n]", nome);
    setbuf(stdin, NULL);
    for (i = 0; nome[i] != '\0'; i++)
        printf("%c", nome[i]);
}