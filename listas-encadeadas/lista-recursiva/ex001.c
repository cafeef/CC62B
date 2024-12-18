/*s ii, iii, vi, vii, ix, xv*/
#include <stdio.h>
#include <stdlib.h>


typedef struct No {
    int chave;
    struct No *prox;
} TNo;

TNo *alocaNo(int k);
void InsereFinal(TNo **lista, int k);
void Imprimir(TNo *lista);

int main() {
    TNo *lista = NULL;
    InsereFinal(&lista, 10);
    InsereFinal(&lista, 20);
    Imprimir(lista);
}

TNo *alocaNo(int k) {
    TNo *novo = (TNo *) malloc(sizeof(TNo));
    if (novo) {
        novo->chave = k;
        novo->prox = NULL;
        return novo;
    }
    return NULL;
}

void InsereFinal(TNo **lista, int k) {
    TNo *novo = alocaNo(k);
    if (!novo) printf("Erro em alocar memória!\n");
    else {
        if (!*lista) {
            *lista = novo;
            return;
        }
        if (!(*lista)->prox) 
            (*lista)->prox = novo;
        else {
            InsereFinal(&(*lista)->prox, k);
        }
    }
}

void Imprimir(TNo *lista) {
    if (!lista)
        return;
    else {
        printf("%d ", lista->chave);
        return Imprimir(lista->prox);
    }  
}