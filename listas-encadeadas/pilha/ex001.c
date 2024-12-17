#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int chave;
    struct No *prox;
} TNo;

typedef struct cabeca {
    TNo *inicio;
    TNo *fim;
} TCabeca;

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

void transfere(TNo **pa, TNo **pb) {
    if (!*pa) printf("Pilha A vazia!\n");
    else {
        while (*pa) { //transfere todos
            empilhar(pb, (*pa)->chave);
            desempilhar(pa);
        }
    }
}

TCabeca *criacabeca() {
    TCabeca *lista = (TCabeca *) malloc(sizeof(TCabeca));
    if (lista) {
        lista->inicio = NULL;
        lista->fim = NULL;
        return lista;
    }
    else return NULL;
}

void enfileirar(TCabeca *p, int k) {
    TNo *novo = (TNo *) malloc(sizeof(TNo));;
    if (novo) {
        novo->chave = k;
        if (!p->inicio) {
            p->inicio = novo;
            p->fim = novo;
        }   
        else
            p->fim->prox = novo;
            p->fim = novo;

    }
}

void desenfileirar(TCabeca *p) {
    if (p) {
        TNo *aux = p->inicio;
        p->inicio = aux->prox;
        if (!p->inicio)
            p->fim = NULL;
        free(aux);
        aux = NULL;
    }
    else printf("Não existe nó cabeça!\n");
}

void FilhaPilha(TCabeca *fila, TNo **pilha) {
    if (fila->inicio) {
        while (fila->inicio) {
            empilhar(pilha, fila->inicio->chave);
            desenfileirar(fila);
        }
        printf("Transferência completa\n");
    }
    else {
        printf("Não tem fila...\n");
        return;
    }
}

void PilhaFila (TCabeca *fila, TNo **pilha) {
    if (*pilha) {
        while (*pilha) {
            enfileirar(fila, (*pilha)->chave);
            desempilhar(pilha);
        }
    }
    else {
        printf("Pilha vazia!\n");
        return;
    }
}

int main() {
    TNo *topoA = NULL, *topoB = NULL;
    TCabeca *fila = criacabeca();
    enfileirar(fila, 56);
    enfileirar(fila, 73);
    enfileirar(fila, 92);
    enfileirar(fila, 84);
    imprimir(fila->inicio);
    printf("\n");
    empilhar(&topoA, 1);
    empilhar(&topoA, 2);
    empilhar(&topoA, 3);
    empilhar(&topoA, 4);
    PilhaFila(fila, &topoA);
    imprimir(fila->inicio);
    printf("\n");
}