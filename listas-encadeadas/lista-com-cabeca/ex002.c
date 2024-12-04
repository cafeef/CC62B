#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int chave;
    struct No *prox;
} TNo;

typedef struct NoCabeca {
    int cont;
    TNo *inicio;
    TNo *fim;
} TCabeca;

TCabeca *criaCabeca();
TNo *alocaNo(int k);
void insereListaI(TCabeca *lista, int k);
void removeListaI(TCabeca *lista);
void imprime(TNo *lista);
void insereListaF(TCabeca *lista, int k);
void removerListaF (TCabeca *lista);
//insere lista f e remove lista f - tarefa

int main() {
    TCabeca *cabeca = criaCabeca();
    insereListaI(cabeca, 8);
    insereListaI(cabeca, 3);
	imprime(cabeca->inicio);
	insereListaF(cabeca, 7);
    imprime(cabeca->inicio);
	removerListaF(cabeca);
	imprime(cabeca->inicio);
}

TCabeca *criaCabeca() {
    TCabeca *cabeca = (TCabeca *)malloc(sizeof(TCabeca));
    if (!cabeca) return NULL;
    cabeca->cont = 0;
    cabeca->inicio = NULL;
    cabeca->fim = NULL;
    return cabeca;
}

TNo *alocaNo(int k) {
    TNo *novo = NULL;
    novo = (TNo *) malloc(sizeof(TNo));
    if (novo) {
        novo->chave = k;
        novo ->prox = NULL;
        return novo;
    }
    return NULL;
}

void insereListaI(TCabeca *lista, int k) {
	TNo *novo = NULL;
	if(!lista->inicio) {
		novo = (TNo *) malloc(sizeof(TNo));
		novo = alocaNo(k);
		if(novo) {
			lista->inicio = novo;
			lista->fim = novo;
			lista->cont++;
		}
	}
	else {
		novo = alocaNo(k);
		if (novo) {
			novo->prox = lista->inicio;
			lista->inicio = novo;
			lista->cont++;
		}
	}
}


void imprime(TNo *lista) {
	if(!lista) {
		printf("Lista vazia!\n");
	}
	else {
		while (lista) {
			printf("%d ", lista->chave);
			lista = lista->prox;
		}
		printf("\n");
	}
}

void removeListaI(TCabeca *lista) {
	if(!lista->inicio) {
		printf("Lista vazia!\n");
		return;
	}
	else {
		TNo *aux = lista->inicio; //aux recebe primeiro elemento
		lista->inicio = aux->prox; 
		lista->cont--;
		free(aux);
		aux = NULL;	
		if (!lista->inicio) 
			lista->fim = NULL;

	}
}

void insereListaF(TCabeca *lista, int k) {
	if (!lista->inicio) insereListaI(lista, k);
	else {
		TNo *novo = alocaNo(k);
		TNo *aux = lista->fim;
		if (novo) {
			aux->prox = novo;
			lista->fim = novo;
			lista->cont++;
		}
 	}
}

void removerListaF (TCabeca *lista) {
	if(!lista->inicio) {
		printf("Lista vazia!\n");
		return;
	}
	else {
		TNo *aux = lista->fim;
		TNo *penultimo = lista->inicio;
		while (penultimo->prox != lista->fim)
			penultimo = penultimo->prox;
		penultimo->prox = NULL;
		lista->fim = penultimo;
		free(aux);
		aux = NULL;
	}
}