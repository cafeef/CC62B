#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
	char ip[20];
	char dom[25];
	struct No *prox;
} TNo;

typedef struct cabeca {
	int qnt;
	TNo *inicio;
} TCabeca;

TCabeca *criacabeca();
TNo *alocaNo(const char *ip, const char *dominio);
void Insere(TCabeca *lista, const char *ip, const char *dominio);
void imprimir(TNo *p);
void buscaIp(TNo *p, const char *ip);
void remover(TCabeca *lista);

int main() {
	TCabeca *lista = criacabeca();
	char ip[20];
	Insere(lista, "192.168.0.1", "www.facebook.com");
	Insere(lista, "172.217.28.206", "www.google.com");
	Insere(lista, "104.18.34.177", "www.reddit.com");
	Insere(lista, "104.16.25.235", "www.cloudflare.com");
	Insere(lista, "198.252.206.16", "www.stackexchange.com");
	printf("Informe o IP: ");
	scanf("%s", ip);
	buscaIp(lista->inicio, ip);
	while (lista->inicio) {
		remover(lista);
	}
}

TCabeca *criacabeca() {
	TCabeca *novo = (TCabeca *) malloc(sizeof(TCabeca));
	if (novo) {
		novo->qnt = 0;
		novo->inicio = NULL;
		return novo;
	}
	else return NULL;
}

TNo *alocaNo(const char *ip, const char *dominio) {
	TNo *novo = (TNo *) malloc(sizeof(TNo));
	if (novo) {
		strcpy(novo->ip, ip);
		strcpy(novo->dom, dominio);
		novo->prox = NULL;
		return novo;
	}
	else return NULL;
}

void Insere(TCabeca *lista, const char *ip, const char *dominio) {
	TNo *novo = alocaNo(ip, dominio);
	if (novo) {
		if (!lista->inicio) {
			lista->inicio = novo;
			lista->qnt++;
		}
		else {
			novo->prox = lista->inicio;
			lista->inicio = novo;
			lista->qnt++;
		}
	}
	else return;
}

void imprimir(TNo *p) {
	while(p) {
		printf("%s: %s\n", p->ip, p->dom);
		p = p->prox;
	}
}

void buscaIp(TNo *p, const char *ip) {
	if (p) {
		while (p) {
			if (!strcmp(p->ip, ip)) {
				printf("%s\n", p->dom);
				break;
			}
			else
				p = p->prox;
		}
		if (!p) printf("IP não encontrado.\n");
	}
	else printf("Lista vazia!\n");	
}

void remover(TCabeca *lista) {
	TNo *aux = lista->inicio;
	if (aux) {
		lista->inicio = aux->prox;
		free(aux);
		aux = NULL;
	}
	else printf("Lista vazia!\n");
}