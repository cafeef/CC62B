#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef struct No {
    int chave;
    struct No *prox;
} TNo;

TNo *alocaNo(int k);
void InsereLista(TNo **lista, int k);
void InsereListaFinal(TNo **lista, int k);
void imprimeLista(TNo *lista);
TNo *buscar(TNo *lista, int k);
int valor_max(TNo *lista);
int valor_min(TNo *lista);
int soma(TNo *lista);
int tamanho(TNo *lista);
int frequencia(TNo *lista, int k);
void removeLista(TNo **lista, int k);

int main() {
    SetConsoleOutputCP(CP_UTF8);
    TNo *lista = NULL, *endereco = NULL;
    InsereLista(&lista, 8);
    InsereListaFinal(&lista, 10);
    InsereListaFinal(&lista, 14);
    InsereListaFinal(&lista, 10);
    imprimeLista(lista);
    endereco = buscar(lista, 10);
    if (!endereco) 
        printf("Não encontrado.");
    else 
        printf("\nEndereço: %x", endereco);
    printf("\nMaior valor: %d", valor_max(lista));
    printf("\nMenor valor: %d", valor_min(lista));
    printf("\nSoma: %d", soma(lista));
    printf("\nTamanho: %d", tamanho(lista));
    printf("\nFrequência número 10: %d", frequencia(lista, 10));
    removeLista(&lista, 20);
}

TNo *alocaNo(int k) {
    TNo *novo = NULL;
    novo = (TNo *) malloc(sizeof(TNo));
    if (!novo) return NULL;
    novo->chave = k;
    novo->prox = NULL;
    return novo;
}

void InsereLista(TNo **lista, int k) {
    TNo *novo = alocaNo(k);
    if (novo) {
        novo->prox = *lista;
        *lista = novo;
    }
}

void InsereListaFinal(TNo **lista, int k) {
    TNo *novo = alocaNo(k);
    if (!(*lista)) {
        InsereLista(lista, k);
        return;
    }
    if (novo) {
        TNo *aux = *lista;
        while (aux->prox != NULL) 
            aux = aux->prox;
        aux->prox = novo;
    }
}

void imprimeLista(TNo *lista) {
    while (lista) {
        printf("%d ", lista->chave);
        lista = lista->prox;
    }
}

TNo *buscar(TNo *lista, int k) {
    while (lista) {
        if (lista->chave == k) 
            return lista;
        lista = lista->prox;
    }
    return NULL;
}

int valor_max(TNo *lista) {
    int maior = 0;
    while(lista) {
        if ((lista->chave) > maior)
            maior = lista->chave;
        lista = lista->prox;
    }
    return maior;
}

int valor_min(TNo *lista) {
    int menor = 1000;
    while(lista) {
        if ((lista->chave) < menor)
            menor = lista->chave;
        lista = lista->prox;
    }
    return menor;
}

int soma(TNo *lista) {
    int soma = 0;
    while(lista) {
        soma += lista->chave;
        lista = lista->prox;
    }
    return soma;
}

int tamanho(TNo *lista) {
    int tamanho = 0;
    while(lista) {
        tamanho += 1;
        lista = lista->prox;
    }
    return tamanho;
}

int frequencia(TNo *lista, int k) {
    int frequencia = 0;
    while (lista) {
        if (lista->chave == k) 
            frequencia++;
        lista = lista->prox;
    }
    return frequencia;
}

void removeLista(TNo **lista, int k) {
    TNo *endereco = buscar(*lista, k);
    TNo *aux = *lista;
    if (!endereco)
        printf("\nElemento não está na lista");
    else {
        if (aux == endereco)
            aux = endereco->prox;
        else {
            TNo *anterior = *lista; 
            while (anterior->prox != endereco) {
                anterior = anterior->prox; // Encontrar o nó anterior
            }
            anterior->prox = endereco->prox; // Ajustar ponteiro
            free(endereco); // Desalocar memória do nó removido
        }
        printf("\n");
        imprimeLista(*lista);      
    }
}