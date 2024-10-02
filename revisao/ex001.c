#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int main() {
    int horas, minutos, total;
    setlocale(LC_ALL, "Portuguese_Brasil");
    puts("Digite as horas: ");
    scanf("%d", &horas);
    puts("Digite os minutos: ");
    scanf("%d", &minutos);
    total = horas * 60 + minutos;
    printf("O total de minutos é: %d", total);
}