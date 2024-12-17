#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int chave;
    struct No *prox;
} TNo;

TNo *alocaNo(int k) {
    TNo *novo = (TNo *) malloc(sizeof(TNo));
    if (novo) {
        novo->chave = k;
        novo->prox = NULL;
        return novo;
    }
    else return NULL;
}

void empilhar(TNo **p, int k) { //push
	TNo *novo = alocaNo(k);
	if (novo) {
		novo->prox = *p; //primeiro elemento da lista
		*p = novo;
	}
    else return;
}

void desempilhar(TNo **p) { //pop
    if (*p) {
        TNo *aux = *p;
        *p = (*p)->prox;
        free(aux);
        aux = NULL;
    }
    else printf("Pilha vazia!\n");
}

void imprimir(TNo *p) {
    if (p) {
        while (p) {
            printf("%d ", p->chave);
            p = p->prox;
        }
    }
    else printf("Pilha vazia!\n");
}

int main() {
    TNo *lista = NULL;
    desempilhar(&lista);
    empilhar(&lista, 16);
    imprimir(lista);
}