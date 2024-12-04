#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct no {
	int chave;
	struct no *prox;
} TNo;

void insereInicio(TNo **p, int k);
void removeInicio(TNo **p);
void imprimeCircular(TNo *p);

int main() {

}

void insereInicio(TNo **p, int k) {
	assert(p);
	if(!*p) {
		*p = (TNo *) malloc(sizeof(TNo));
		if(*p) {
			(*p)->chave = k;
			(*p)->prox = *p;
		}
	}
	else {
		TNo *novo = (TNo *) malloc(sizeof(TNo));
		if(!novo) return;
		novo->chave = k;
		novo->prox = (*p)->prox;
		(*p)->prox = novo;
	}
}

void removeInicio(TNo **p) {
	assert(p);
	if(!*p) {
		printf("Lista vazia!\n");
		return;
	}
	else {
		TNo *prim = (*p)->prox;
		(*p)->prox = prim->prox;
		free(prim);
		prim = NULL;
		//se tiver só um elemento
	}
}