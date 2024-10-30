/*Fazer um programa contendo as seguintes funções:
 Leitura: lê um vetor de números inteiros positivos
 Separa: separa os elementos do vetor em dois vetores, sendo que um deles conterá os números
pares e o outro os números ímpares. Todos os vetores dinâmicos. Não esqueça de liberar
memória quando possível.
 Imprime: exibe na tela os elementos contidos no vetor passado por parâmetro.*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void ler (int **p, int *tam);
void libera(int **p);
void imprime(int **p, int *tam);
void separa(int **p, int *tam);

int main() {
    int tam, i, *p;
    setlocale(LC_ALL, "Portuguese");
    printf("Informe o tamanho do vetor: ");
    scanf("%d", &tam);
    ler(&p, &tam);
    separa(&p, &tam);
    printf("Vetor total: ");
    imprime(&p, &tam);
}

void ler (int **p, int *tam) {
    int i;
    *p = (int *) malloc(sizeof(int) * *tam);
    for (i = 0; i < *tam; i++) {
        printf("Digite o %d� termo: ", i + 1);
        scanf("%d", &*(*p + i));
    }
}

void libera(int **p) {
    free(*p);
    *p = NULL;
}

void imprime(int **p, int *tam) {
    int i;
    for(i = 0; i < *tam; i++)
        printf("%d ", *(*p + i));
    libera(&p);
}

void separa(int **p, int *tam) {
    int i, cP = 0, cI = 0, elemento, ip = 0, ii = 0;
    int *pp, *pi;
    for (i = 0; i < *tam; i++) {
        elemento = *(*p + i);
        if ((elemento % 2) == 0)
            cP++;
        else
            cI++;
    }
    pp = (int *) malloc(sizeof(int) * cP);
    pi = (int *) malloc(sizeof(int) * cI);
    for (i = 0; i < *tam; i++) {
        elemento = *(*p + i);
        if ((elemento % 2) == 0) {
            *(pp + ip) = elemento;
            ip++;
        }
        else {
            *(pi + ii) = elemento;
            ii++;
        }
    }
    printf("Vetor par: ");
    imprime(&pp, &cP);
    printf("Vetor �mpar: ");
    imprime(&pi, &cI);
    libera(&p);
}


