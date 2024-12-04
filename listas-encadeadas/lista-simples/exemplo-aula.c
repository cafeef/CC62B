#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct no {
	int chave;
	struct no *prox;
} TNo;

TNo *aloca(int k);
void insereLista(TNo **p, int k); //inicio
void removeLista(TNo **p); //inicio
void imprimir(TNo *p);
void inserirfinal (TNo **p, int k);

int main() {
	TNo *lista = NULL; //LISTA É O PONTEIRO PARA O PRIMEIRO
	int op, k;
	while (op != 6) {
		printf("\nDigite sua opção:\n1 - Insere\n2 - Imprime\n3 - Remove\n4 - Remove todos\n5 - Inserir no final\n6 - Sair\n");
		scanf("%d", &op);
		switch (op) {
			case 1:
				printf("Digite o valor: ");
				scanf("%d", &k);
				insereLista(&lista, k);
				break;
			case 2:
				imprimir(lista);
				break;
			case 3:
				removeLista(&lista);
				break;
			case 4:
				while (lista) {
					removeLista(&lista);
				}
				break;
			case 5:
				printf("Digite o valor: ");
				scanf("%d", &k);
				inserirfinal(&lista, k);
				break;
			case 6:
				return 1;
			default:
				printf("Opção inválida!");
				break;
		}
	}

}

TNo *aloca(int k) {
	TNo *novo = NULL;
	novo = (TNo *)malloc(sizeof(TNo));
	if (novo) {
		novo->chave = k;
		novo->prox = NULL;
		return novo;
	}
	return NULL; 
}

void insereLista(TNo **p, int k) {
	TNo *novo = NULL;
	novo = aloca(k);
	if (novo) {
		novo->prox = *p; //primeiro elemento da lista
		*p = novo;
	}
}

void imprimir(TNo *p) {
	if (p == NULL) printf("Lista vazia!");
	while (p) {
		printf("%d ", p->chave);
		p = p->prox;
	}
}

void removeLista(TNo **p) {
	if (*p) {
		TNo *aux = *p;
		*p = (*p)->prox;
		free(aux);	
	}
	else printf("Lista vazia!");
	
}

void inserirfinal (TNo **p, int k) {
	TNo *novo = NULL;
	if(*p == NULL) {
		insereLista(p, k);
		return;
	}
	novo = aloca(k);
	if (novo) {
		TNo *aux = *p;
		while (aux->prox != NULL)
			aux = aux->prox;
		aux->prox = novo;
	}
}