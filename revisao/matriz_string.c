#include <stdio.h>

int main() {
    char matriz_string[3][20];
    int i;
    for (i = 0; i < 3; i++) {
        printf("Informe o primeiro nome do %d aluno: ", i + 1);
        fgets(matriz_string[i], 20, stdin);
    }
    for (i = 0; i < 3; i++)
        printf("Aluno %d: %s", i + 1, matriz_string[i]);
}